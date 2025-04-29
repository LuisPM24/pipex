/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:01:24 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:01:28 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	mem;
	int	cont;

	sign = 1;
	mem = 0;
	cont = 0;
	while (nptr[cont] == ' ' || (nptr[cont] >= 9 && nptr[cont] <= 13))
		cont++;
	if (nptr[cont] == '+' || nptr[cont] == '-')
	{
		if (nptr[cont] == '-')
			sign *= -1;
		cont++;
	}
	if (nptr[cont] == '+' || nptr[cont] == '-')
		return (0);
	while (nptr[cont] >= 48 && nptr[cont] <= 57)
	{
		mem = (mem * 10) + ((int)nptr[cont] - '0');
		cont++;
	}
	return (mem * sign);
}
