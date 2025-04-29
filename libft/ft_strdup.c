/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:12:34 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:12:36 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	cont;
	void	*mem;
	char	*str_cpy;

	size = 0;
	cont = 0;
	while (s[size] != '\0')
		size++;
	mem = malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	str_cpy = (char *)mem;
	while (cont < size)
	{
		str_cpy[cont] = s[cont];
		cont++;
	}
	str_cpy[cont] = '\0';
	return (str_cpy);
}
