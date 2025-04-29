/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:11 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/20 11:28:06 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[cont1] != '\0' && cont1 < len)
	{
		cont2 = 0;
		while ((big[cont1 + cont2] == little[cont2]) && ((cont1 + cont2) < len))
		{
			cont2++;
			if (little[cont2] == '\0')
				return ((char *)(big + cont1));
		}
		cont1++;
	}
	return (NULL);
}
