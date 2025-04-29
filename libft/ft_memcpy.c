/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:01 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/15 11:17:03 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				cont;
	unsigned char		*ptr;
	const unsigned char	*str;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	ptr = (unsigned char *)dest;
	str = (const unsigned char *)src;
	cont = 0;
	while (cont < n)
	{
		ptr[cont] = str[cont];
		cont++;
	}
	return (dest);
}
