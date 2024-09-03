/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:04:32 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:18:45 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst_size == 0)
		return (src_len);
	while (*src && dst_size - 1)
	{
		*dst = *src;
		dst_size--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (src_len);
}
