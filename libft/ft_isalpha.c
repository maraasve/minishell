/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:19:49 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/27 21:24:50 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c = 'a';
    printf("%i\n", ft_isalpha(c));
	printf("%i\n", isalpha(c));
    return (0);
}*/