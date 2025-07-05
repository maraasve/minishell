/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:20:18 by andmadri          #+#    #+#             */
/*   Updated: 2025/07/05 14:53:46 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = 0;
	if (nelem == 0 || elsize == 0)
	{
		ptr = malloc(1);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	else if ((nelem * elsize) / elsize != nelem)
		return (0);
	ptr = malloc(elsize * nelem);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
