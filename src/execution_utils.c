/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:46:45 by andmadri          #+#    #+#             */
/*   Updated: 2024/06/27 21:46:09 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	dup_fds(t_data *data, t_command *command)
{
	if (command->in_fd != STDIN_FILENO || dup2(command->in_fd, STDOUT_FILENO) == -1)
	{
		if (command->in_fd == -1)
		{
			data->exit_status = 1;
			exit(terminate_minishell(data, NULL));
		}
		if (!is_builtin(command->argv[0]))
		{
			if (dup2(command->in_fd, STDIN_FILENO) == -1)
			{
				data->exit_status = 1;
				exit(terminate_minishell(data, NULL));
			}
			close(command->in_fd);
		}
	}
	if (command->out_fd != STDOUT_FILENO)
	{
		if (command->out_fd == -1 || dup2(command->out_fd, STDOUT_FILENO) == -1)
		{
			data->exit_status = 1;
			exit(terminate_minishell(data, NULL));
		}
		if (!is_builtin(command->argv[0]))
		{
			if (dup2(command->out_fd, STDIN_FILENO) == -1)
			{
				data->exit_status = 1;
				exit(terminate_minishell(data, NULL));
			}
			close(command->out_fd);
		}
	}
	if (command->pipe)
		close(command->pipe_fd[0]);
}

bool	paths_exists(t_data *data, char **paths_array)
{
	if (!paths_array)
	{
		ft_putstr_fd("minishell: No such file or directory\n", 2);
		data->exit_status = CMD_NOT_F;
		return (false);
	}
	return (true);
}

bool	access_true(t_data *data, char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		return (true);
	}
	if (access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
	{
		data->exit_status = CMD_NOT_X;
		ft_putstr_fd("minishell: Command not executable\n", 2);
		return (true);
	}
	return (false);
}

int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0)
		return (true);
	if (ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0)
		return (true);
	if (ft_strncmp(cmd, "env", ft_strlen("env")) == 0)
		return (true);
	if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0)
		return (true);
	if (ft_strncmp(cmd, "export", ft_strlen("export")) == 0)
		return (true);
	if (ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0)
		return (true);
	if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		return (true);
	return (false);
}
