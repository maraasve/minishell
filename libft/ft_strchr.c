/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:53:14 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:27 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)c == (unsigned char )*str)
			return ((char *)str);
		else
			str++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)str);
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	//const char *str = "Hello World";
	char s[] = "tripouille";
	printf("%s\n", (char *)ft_strchr(s, 't' + 256));
	//printf("%s\n", (char *)strchr(s, ));
	return (0);
}*/