/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:48:58 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:18:30 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	else if (len > s_len - start)
		len = s_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return ((char *)ptr);
}
