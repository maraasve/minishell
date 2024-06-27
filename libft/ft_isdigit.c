/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:30:07 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/02 22:20:21 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int c = '0';
    printf("%i", ft_isdigit(c));
	printf("%i", isdigit(c))
    return (0);
}*/
