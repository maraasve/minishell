/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:39:43 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:16:40 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n != 0)
	{
		if (*((unsigned char *)str) == (unsigned char)c)
			return ((void *)str);
		else
		{
			str++;
		}
		n--;
	}
	return (0);
}
