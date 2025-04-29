/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:07:26 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/29 14:23:59 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
	{
		free(split[count]);
		count++;
	}
	free(split);
}

void	free_execve(char **command, char *command_path)
{
	int	count;

	count = 0;
	while (command[count])
	{
		free(command[count]);
		count++;
	}
	free(command);
	free(command_path);
	error();
}
