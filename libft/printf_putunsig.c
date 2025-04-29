/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putunsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:45:47 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 12:29:35 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_putunsig(unsigned int nb, int *printed)
{
	int	aux;

	if (nb == 4294967295)
	{
		write(1, "4294967295", 10);
		*printed += 10;
		return ;
	}
	if (nb >= 10)
		printf_putunsig(nb / 10, printed);
	aux = (nb % 10) + '0';
	write(1, &aux, 1);
	(*printed)++;
}
