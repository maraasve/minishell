/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:29:18 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/02 22:52:31 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	return (c);
}
/*
#include<stdio.h>
#include<ctype.h>

int	main(void)
{
	int c = '8';
	printf("%i\n", ft_toupper(c));
	printf("%i\n", toupper(c));
	return (0);
}*/