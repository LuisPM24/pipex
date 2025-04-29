/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:22:37 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/07 18:08:09 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen_gnl(const char *s)
{
	size_t	cont;

	cont = 0;
	if (s == NULL)
		return (0);
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

unsigned int	ft_strlcpy_gnl(char *dst, const char *src, unsigned int size)
{
	unsigned int	cont;

	cont = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (size > 0)
	{
		while (src[cont] != '\0' && cont < size - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = '\0';
	}
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strdup_gnl(const char *s)
{
	size_t	size;
	char	*str_cpy;

	size = 0;
	if (!s)
		return (NULL);
	size = ft_strlen_gnl(s);
	str_cpy = (char *)malloc(size + 1);
	if (str_cpy == NULL)
		return (NULL);
	ft_strlcpy_gnl(str_cpy, s, size + 1);
	return (str_cpy);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, s1, len1 + 1);
	ft_strlcpy_gnl(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s || !s[0])
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
