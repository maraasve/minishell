/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:30:04 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:17:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *((unsigned char *)s1) == *((unsigned char *)s2))
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
