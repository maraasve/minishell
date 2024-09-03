/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:53:14 by andmadri          #+#    #+#             */
/*   Updated: 2024/09/03 15:17:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)c == (unsigned char )*str)
			return ((char *)str);
		else
			str++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)str);
	}
	return (0);
}
