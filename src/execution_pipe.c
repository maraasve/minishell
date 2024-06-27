/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:09:32 by marieke           #+#    #+#             */
/*   Updated: 2024/06/27 21:36:38 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static int	execute_builtin(t_data *data, t_command *command, char **paths)
{
	if (command->pipe)
		close(command->pipe_fd[0]);
	free_dbl_array(&paths);
	if (ft_strncmp(command->argv[0], "cd", ft_strlen("cd")) == 0)
		return (ft_cd(data, command));
	else if (ft_strncmp(command->argv[0], "echo", ft_strlen("echo")) == 0)
		return (ft_echo(data, *command));
	else if (ft_strncmp(command->argv[0], "env", ft_strlen("env")) == 0)
		return (ft_env(data, command, true));
	else if (ft_strncmp(command->argv[0], "exit", ft_strlen("exit")) == 0)
		ft_exit(data, data->cmd_head, command, paths);
	else if (ft_strncmp(command->argv[0], "export", ft_strlen("export")) == 0)
		return (ft_export(data, command));
	else if (ft_strncmp(command->argv[0], "pwd", ft_strlen("pwd")) == 0)
		return (ft_pwd(data, command, true));
	else if (ft_strncmp(command->argv[0], "unset", ft_strlen("unset")) == 0)
		return (ft_unset(data, command));
	return (EXIT_FAILURE);
}

static void	execute_cmd(t_data *data, t_command *command, char **paths)
{
	char	*cmd;

	command->pid = fork();
	if (command->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup_fds(data, command);
		if (is_builtin(command->argv[0]))
		{
			data->exit_status = execute_builtin(data, command, paths);
			exit(terminate_minishell(data, NULL));
		}
		cmd = get_command(data, paths, command->argv[0]);
		if (!cmd || data->exit_status == CMD_NOT_F || \
		data->exit_status == CMD_NOT_X)
			exit(terminate_minishell(data, paths));
		else
		{
			free_dbl_array(&paths);
			if (execve(cmd, command->argv, data->env) == -1)
				data->exit_status = 2;
		}
		exit(terminate_minishell(data, paths));
	}
}

static int	set_fds(t_command *command, t_command *prev_cmd)
{
	if (command->argv && command->pipe)
	{
		if (pipe(command->pipe_fd) < 0)
		{
			write(2, "pipe: ", 10);
			return (EXIT_FAILURE);
		}
		if (command->out_fd == STDOUT_FILENO)
			command->out_fd = command->pipe_fd[1];
	}
	if (prev_cmd && command->in_fd == STDIN_FILENO)
		command->in_fd = prev_cmd->pipe_fd[0];
	return (EXIT_SUCCESS);
}

static void	wait_child(t_data *data, t_command *cmd, t_command *prev_cmd)
{
	t_command	*cur_cmd;

	cur_cmd = cmd;
	while (cur_cmd && cur_cmd->pid != -1)
	{
		set_signal_handler(RUNNING, cur_cmd);
		waitpid(cur_cmd->pid, &data->exit_status, 0);
		if (WIFSIGNALED(data->exit_status) && cur_cmd->in_fd != -1 && cur_cmd->out_fd != -1)
			data->exit_status += 128;
		if (WIFEXITED(data->exit_status))
			data->exit_status = WEXITSTATUS(data->exit_status);

		cur_cmd = cur_cmd->pipe;
	}
	if (prev_cmd)
		close(prev_cmd->pipe_fd[0]);
	set_signal_handler(FALSE, cmd);
}

int	execution_pipe(t_data *data, t_command *command, char **paths)
{
	t_command	*cur_cmd;
	t_command	*prev_cmd;

	cur_cmd = command;
	prev_cmd = NULL;
	while (cur_cmd)
	{
		set_fds(cur_cmd, prev_cmd);
		if (cur_cmd->argv)
		{
			if (!cur_cmd->pipe && !prev_cmd && is_builtin(cur_cmd->argv[0]))
				return (execute_builtin(data, cur_cmd, paths));
			else if (cur_cmd->argv)
				execute_cmd(data, cur_cmd, paths);
			if (cur_cmd->pipe)
				close(cur_cmd->pipe_fd[1]);
			if (prev_cmd && prev_cmd->pipe)
				close(prev_cmd->pipe_fd[0]);
			if (cur_cmd->pipe)
				prev_cmd = cur_cmd;
		}
		cur_cmd = cur_cmd->pipe;
	}
	wait_child(data, command, prev_cmd);
	return (free_dbl_array(&paths), data->exit_status);
}
