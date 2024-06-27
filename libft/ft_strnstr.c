/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:49:03 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/28 17:11:53 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	length_lil;

	length_lil = ft_strlen(lil);
	if (*lil == '\0')
		return ((char *)big);
	while (*big)
	{
		if (len < length_lil)
			return (0);
		if (ft_strncmp(big, lil, length_lil) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char big[30] = "aaabcabcd";
// 	char lil[10] = "cd";
// 	printf("%s", ft_strnstr(big, "cd", 8));
// 	//printf("%d", strnstr(big, lil, -1));
// }