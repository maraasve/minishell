/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:01:28 by marieke           #+#    #+#             */
/*   Updated: 2024/06/27 13:49:09 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static void	heredoc_child(t_data *data, char *del, int *pipe_fd, char **pth)
{
	char	*str;

	str = NULL;
	signal(SIGINT, SIG_DFL);
	while (ft_strncmp(str, del, ft_strlen(del)) != 0)
	{
		if (str)
		{
			ft_putstr_fd(str, pipe_fd[1]);
			ft_putstr_fd("\n", pipe_fd[1]);
			free(str);
		}
		str = readline("> ");
		if (!str)
			exit(1);
	}
	free(str);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	terminate_minishell(data, pth);
	exit(0);
}

void	ft_heredoc(t_data *data, t_command *command, char **paths)
{
	int		pipe_fd[2];
	int		i;

	i = 0;
	while (command->delimiter && command->delimiter[i])
	{
		if (pipe(pipe_fd) < 0)
			exit (1);
		command->in_fd = pipe_fd[0];
		command->pid = fork();
		if (command->pid == 0)
			heredoc_child(data, command->delimiter[i], pipe_fd, paths);
		set_signal_handler(RUNNING, NULL);
		close(pipe_fd[1]);
		if (command->delimiter[i + 1] != NULL)
			close(pipe_fd[0]);
		waitpid(command->pid, &data->exit_status, 0);
		if (WIFSIGNALED(data->exit_status))
			data->exit_status += 128;
		if (WIFEXITED(data->exit_status))
			data->exit_status = WEXITSTATUS(data->exit_status);
		i++;
	}
	set_signal_handler(FALSE, NULL);
}
