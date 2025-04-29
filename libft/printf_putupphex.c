/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putupphex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:41:33 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 12:29:54 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	turn_result(char *buffer, int cont)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = cont - 1;
	while (start < end)
	{
		aux = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = aux;
		start++;
		end--;
	}
}

static void	hex_converter(char *buffer, unsigned int nb)
{
	char	*hex_digits;
	int		cont;

	hex_digits = "0123456789ABCDEF";
	cont = 0;
	if (nb == 0)
		buffer[cont++] = '0';
	while (nb > 0)
	{
		buffer[cont++] = hex_digits[nb % 16];
		nb /= 16;
	}
	buffer[cont] = '\0';
	turn_result(buffer, cont);
}

void	printf_putupphex(unsigned int nb, int *printed)
{
	char	buffer[16];

	hex_converter(buffer, nb);
	printf_putstr(buffer, printed);
}
