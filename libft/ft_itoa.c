/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:34:01 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/22 10:34:02 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*write_number(int n, char *str, int is_ngtv)
{
	size_t	len;

	len = calc_len(n);
	str = (char *)malloc(len + is_ngtv + 1);
	if (!str)
		return (NULL);
	str[len + is_ngtv] = '\0';
	if (is_ngtv)
	{
		str[0] = '-';
		n = -n;
	}
	while (len > 0)
	{
		str[len + is_ngtv - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = "";
	if (n < 0)
	{
		if (n == -2147483648)
			str = ft_strdup("-2147483648");
		else
			str = write_number(n, str, 1);
	}
	else if (n > 0)
	{
		if (n == 2147483647)
			str = ft_strdup("2147483647");
		else
			str = write_number(n, str, 0);
	}
	else
		str = ft_strdup("0");
	return (str);
}
