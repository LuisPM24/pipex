/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:27:32 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/27 10:48:45 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		count;

	result = 0;
	sign = 1;
	count = 0;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			break ;
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * sign);
}
