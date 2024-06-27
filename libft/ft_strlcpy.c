/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:04:32 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:09:48 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst_size == 0)
		return (src_len);
	while (*src && dst_size - 1)
	{
		*dst = *src;
		dst_size--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (src_len);
}
/*
#include<stdio.h>
#include <bsd/string.h>
int main(void)
{
	char dest[1];
	char *src = "hello";
	printf("%lu\n", ft_strlcpy(dest, src, sizeof(dest)));
	
	//printf("%lu\n", strlcpy(dest, src, sizeof(dest)));
	
	return (0);
}*/