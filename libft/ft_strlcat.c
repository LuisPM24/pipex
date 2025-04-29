/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:10:33 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/16 17:06:15 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cont;
	size_t	src_size;
	size_t	dst_size;

	dst_size = 0;
	while (dst[dst_size] != '\0')
		dst_size++;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (dst_size >= size)
		return (size + src_size);
	cont = 0;
	while (cont < size - dst_size - 1 && src[cont] != '\0')
	{
		dst[dst_size + cont] = src[cont];
		cont++;
	}
	dst[dst_size + cont] = '\0';
	return (dst_size + src_size);
}
