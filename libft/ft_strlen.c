/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:24:35 by andmadri          #+#    #+#             */
/*   Updated: 2024/06/10 17:11:40 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
    const char *str= "Hello";
    printf("%lu\n", ft_strlen(str));
    printf("%lu\n", strlen(str));
    return (0);
}*/