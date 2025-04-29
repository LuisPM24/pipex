/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putvoid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:12:25 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 12:30:08 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	turn_result(char *buffer, int cont)
{
	int		start;
	int		end;
	char	aux;

	start = 2;
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

static void	hex_converter(char *buffer, unsigned long ptr)
{
	char	*hex_digits;
	int		cont;

	hex_digits = "0123456789abcdef";
	cont = 2;
	if (ptr == 0)
		buffer[cont++] = '0';
	buffer[0] = '0';
	buffer[1] = 'x';
	while (ptr > 0)
	{
		buffer[cont++] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	buffer[cont] = '\0';
	turn_result(buffer, cont);
}

void	printf_putvoid(void *ptr, int *printed)
{
	char	buffer[18];

	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		*printed += 5;
	}
	else
	{
		hex_converter(buffer, (unsigned long)ptr);
		printf_putstr(buffer, printed);
	}
}
