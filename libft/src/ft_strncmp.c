/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:23:42 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:18:39 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (1);
	if (n == 0)
		return (0);
	while (--n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
