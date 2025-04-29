/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:11:31 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/14 17:11:33 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cont;
	unsigned char	*ptr;

	cont = 0;
	ptr = (unsigned char *)s;
	while (cont < n)
	{
		ptr[cont] = 0;
		cont++;
	}
}
