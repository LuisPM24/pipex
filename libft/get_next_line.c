/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:22:09 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/07 18:05:53 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_text(char **buffer)
{
	int		cont;
	int		len;
	char	*line;

	len = 0;
	cont = 0;
	if (!*buffer || !**buffer)
		return (NULL);
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (cont < len)
	{
		line[cont] = (*buffer)[cont];
		cont++;
	}
	if ((*buffer)[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	next_line(buffer, len);
	return (line);
}

void	next_line(char	**buffer, int len)
{
	char	*new_buffer;

	new_buffer = ft_strdup_gnl(*buffer + len);
	if (!new_buffer)
		return ;
	free(*buffer);
	*buffer = new_buffer;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		bf_read[BUFFER_SIZE + 1];
	char		*aux_to_free;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup_gnl("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (!buffer || ft_strchr_gnl(buffer, '\n'))
			break ;
		bytes_read = read(fd, bf_read, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), buffer = NULL, NULL);
		bf_read[bytes_read] = '\0';
		aux_to_free = ft_strjoin_gnl(buffer, bf_read);
		free(buffer);
		buffer = aux_to_free;
	}
	if (!buffer || *buffer == '\0')
		return (free(buffer), buffer = NULL, NULL);
	return (get_text(&buffer));
}
