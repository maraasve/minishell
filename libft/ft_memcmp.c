/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:30:04 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:35 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	//char *s1 = "Hello";
	//char *s2 = "ello";
	char s[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	printf("%i\n", ft_memcmp(s, s2, 0));
	//printf("%i\n", memcmp(s, s2, 0));
	return (0);
}*/