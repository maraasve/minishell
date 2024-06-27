/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:28:24 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:07:54 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;

	if (dest == NULL && src == NULL)
		return (dest);
	ptr = dest;
	while (n--)
	{
		*((unsigned char *)dest) = *((unsigned char *)src);
		src++;
		dest++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[6];
	const char src[] = "Hello";
	//printf("%p\n", ft_memcpy(dest, src, 3));
	printf("%s\n", (char *)memcpy(dest, src, 3));
	return (0);
}*/