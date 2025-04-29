/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:09:55 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/15 13:09:57 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				cont;
	unsigned char		*ptr;
	const unsigned char	*str;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dest;
	str = (const unsigned char *)src;
	if (str < ptr && ptr < str + n)
	{
		while (n--)
			ptr[n] = str[n];
	}
	else
	{
		cont = 0;
		while (cont < n)
		{
			ptr[cont] = str[cont];
			cont++;
		}
	}
	return (dest);
}
