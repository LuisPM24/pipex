/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:10:10 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:10:12 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*s_copy;

	cont = 0;
	s_copy = (unsigned char *)s;
	while (cont < n)
	{
		if (s_copy[cont] == (unsigned char)c)
			return ((void *)s_copy + cont);
		cont++;
	}
	return (NULL);
}
