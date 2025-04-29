/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:30:56 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/22 12:30:58 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	cont;

	if (!s || !f)
		return ;
	cont = 0;
	while (s[cont])
	{
		f(cont, &s[cont]);
		cont++;
	}
}
