/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:06:23 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:06:26 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			cont;
	void			*mem;
	unsigned char	*mem_ini;

	cont = 0;
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	mem_ini = (unsigned char *)mem;
	while (cont < (nmemb * size))
	{
		mem_ini[cont] = 0;
		cont++;
	}
	return (mem);
}
