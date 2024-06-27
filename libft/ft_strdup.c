/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:23:13 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:12:12 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*cpy_s;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	cpy_s = ptr;
	while (*s)
	{
		*cpy_s = *s;
		cpy_s++;
		s++;
	}
	*cpy_s = '\0';
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	const char *s = "Hello";
	printf("%p\n", ft_strdup(s));
	printf("%p\n", s);
	return (0);
}*/