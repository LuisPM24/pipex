/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:16:18 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/29 14:34:55 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		exec_child_process(fd, argv, envp);
	waitpid(pid1, NULL, 0);
	exec_parent_process(fd, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_putstr_fd("Error:Bad arguments\n", 2);
	else
		pipex(argv, envp);
	return (0);
}
