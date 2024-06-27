/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:53:28 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:21:56 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	const char *str = "Hello world";
	int c = 'h';
	printf("%p\n", ft_strrchr(str, c));
	printf("%p\n", strrchr(str, c));
	return (0);
}*/