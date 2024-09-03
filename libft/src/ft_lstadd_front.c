/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:06:22 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:16:25 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new -> next = *lst;
		*lst = new;
	}
}
