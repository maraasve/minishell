/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:29:14 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/02 22:52:17 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
#include<stdio.h>
#include<ctype.h>

int	main(void)
{
	int c = '8';
	printf("%i\n", ft_tolower(c));
	printf("%i\n", tolower(c));
	return (0);
}*/