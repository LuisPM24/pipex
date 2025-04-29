/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:20:04 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 12:29:17 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printf_putstr(char *str, int *printed)
{
	unsigned int	count;

	count = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		*printed += 6;
		return ;
	}
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
		(*printed)++;
	}
}
