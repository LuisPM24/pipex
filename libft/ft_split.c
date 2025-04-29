/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:47:55 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/22 10:47:57 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	cont;
	size_t	words;
	int		in_word;

	cont = 0;
	words = 0;
	in_word = 0;
	while (s[cont])
	{
		if (s[cont] != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (s[cont] == c)
			in_word = 0;
		cont++;
	}
	return (words);
}

static int	add_word(char const **s, char c, char **str_group, size_t *cont)
{
	const char	*start;
	size_t		len;
	size_t		cont2;

	cont2 = 0;
	while (**s == c)
		(*s)++;
	if (**s == '\0')
		return (1);
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	str_group[*cont] = malloc(len + 1);
	if (!str_group[*cont])
		return (0);
	while (cont2 < len)
	{
		str_group[*cont][cont2] = start[cont2];
		cont2++;
	}
	str_group[*cont][len] = '\0';
	(*cont)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str_group;
	size_t	cont;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str_group = malloc((words + 1) * sizeof(char *));
	if (!str_group)
		return (NULL);
	cont = 0;
	while (*s)
	{
		if (*s != c && !add_word(&s, c, str_group, &cont))
		{
			while (cont--)
				free(str_group[cont]);
			free(str_group);
			return (NULL);
		}
		else if (*s)
			s++;
	}
	str_group[words] = NULL;
	return (str_group);
}
