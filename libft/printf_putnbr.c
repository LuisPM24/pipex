/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:39:15 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 12:29:02 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_putnbr(int nb, int *printed)
{
	int	aux;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*printed += 11;
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		*printed += 1;
		nb = -nb;
	}
	if (nb >= 10)
		printf_putnbr(nb / 10, printed);
	aux = (nb % 10) + '0';
	write(1, &aux, 1);
	(*printed)++;
}
