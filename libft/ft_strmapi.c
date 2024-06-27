/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:17:52 by andmadri          #+#    #+#             */
/*   Updated: 2023/10/27 20:57:04 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// char	ft_fake(unsigned int i, char c)
// {
// 	i = 0;
// 	return (c + 1);
// }
// int main(void)
// {
// 	char s[] = "ABCD";
// 	printf("%s", ft_strmapi(s, ft_fake));
// 	return (0);
// }