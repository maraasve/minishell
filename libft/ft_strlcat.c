/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:30:00 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:09:55 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	while (*src && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = *src;
		src++;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char dest[50] = "My name is andres";
// 	char src[] = " and yours?";
// 	printf("%lu\n", ft_strlcat(dest, src, sizeof(dest)));
// 	printf("%s\n", dest);
// }
