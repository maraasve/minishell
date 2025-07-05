/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:53:28 by andmadri          #+#    #+#             */
/*   Updated: 2025/07/05 14:53:46 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*ptr;

	ptr = 0;
	while (*str)
	{
		if ((unsigned char)c == (unsigned char)*str)
			ptr = str;
		str++;
	}
	if ((unsigned char)c == '\0')
	{
		ptr = str;
		return ((char *)ptr);
	}
	return ((char *)ptr);
}
