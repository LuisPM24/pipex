/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:19:45 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/14 16:19:47 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*ptr;

	cont = 0;
	ptr = (unsigned char *)s;
	while (cont < n)
	{
		ptr[cont] = (unsigned char)c;
		cont++;
	}
	return (s);
}
