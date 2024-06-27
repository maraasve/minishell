/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:39:43 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:26 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *str = "Hello emmer";
	int c = 'l';
	printf("%p\n", ft_memchr(str, c, 2));
	printf("%p\n", memchr(str, c, 2));
	return (0);
}*/