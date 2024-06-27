/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:06:23 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:05:25 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*((unsigned char *)s) = (unsigned char)c;
		s++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "hello";
	int c = 'a';
	ft_memset(s, c, sizeof(s));
	printf("%s", s);
	return (0);
}*/