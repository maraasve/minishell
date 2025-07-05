/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:12:50 by andmadri          #+#    #+#             */
/*   Updated: 2025/07/05 14:58:18 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_pwd(t_data *data, t_command *command, bool print)
{
	if (getcwd(data->pwd, sizeof(data->pwd)) == NULL)
	{
		perror("minishell: pwd");
		data->exit_status = EXIT_FAILURE;
		return (EXIT_SUCCESS);
	}
	if (print == true)
	{
		ft_putstr_fd(data->pwd, command->out_fd);
		ft_putstr_fd("\n", command->out_fd);
	}
	data->exit_status = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}
