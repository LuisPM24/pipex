/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:14:22 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:14:23 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		if ((unsigned char)s1[cont] != (unsigned char)s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		if (s1[cont] == '\0')
			break ;
		cont++;
	}
	return (0);
}
