/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:11:08 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:11:10 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cont;
	unsigned char	*p1;
	unsigned char	*p2;

	cont = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (cont < n)
	{
		if (p1[cont] != p2[cont])
			return (p1[cont] - p2[cont]);
		cont++;
	}
	return (0);
}
