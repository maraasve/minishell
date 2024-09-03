/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:23:13 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:17:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*cpy_s;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	cpy_s = ptr;
	while (*s)
	{
		*cpy_s = *s;
		cpy_s++;
		s++;
	}
	*cpy_s = '\0';
	return (ptr);
}
