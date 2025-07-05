/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:22:43 by andmadri          #+#    #+#             */
/*   Updated: 2025/07/05 14:58:18 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	error_memory_allocation(t_data *data, t_command *command)
{
	ft_putstr_fd("minishell: memory allocation error\n", 2);
	free_all(data, command);
	data->exit_status = EXIT_FAILURE;
	return (EXIT_FAILURE);
}

void	close_pipes(t_command *cur_cmd, t_command *prev_cmd)
{
	if (cur_cmd->pipe)
		close(cur_cmd->pipe_fd[1]);
	if (prev_cmd && prev_cmd->pipe)
		close(prev_cmd->pipe_fd[0]);
}
