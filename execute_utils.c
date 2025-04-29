/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:23 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/29 14:38:43 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*form_path(char **paths, char *command)
{
	char	*command_path;
	char	*command_fullpath;
	int		count;

	count = 0;
	while (paths[count])
	{
		command_path = ft_strjoin(paths[count], "/");
		command_fullpath = ft_strjoin(command_path, command);
		free(command_path);
		if (access(command_fullpath, F_OK) == 0)
		{
			free_split(paths);
			return (command_fullpath);
		}
		free(command_fullpath);
		count++;
	}
	free_split(paths);
	return (NULL);
}

static char	*find_command_path(char *command, char **envp)
{
	char	**paths;
	int		count;

	count = 0;
	while (envp[count] && ft_strnstr(envp[count], "PATH", 4) == 0)
		count++;
	if (!envp[count])
		return (NULL);
	paths = ft_split(envp[count] + 5, ':');
	if (!paths)
		return (NULL);
	return (form_path(paths, command));
}

void	execute_program(char *argv, char **envp)
{
	char	**command;
	char	*command_path;
	int		count;

	command = ft_split(argv, ' ');
	command_path = find_command_path(command[0], envp);
	count = 0;
	if (!command_path)
	{
		while (command[count])
		{
			free(command[count]);
			count++;
		}
		free(command);
		error();
	}
	if (execve(command_path, command, envp) == -1)
		free_execve(command, command_path);
}

void	exec_parent_process(int *fd, char **argv, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_program(argv[3], envp);
}

void	exec_child_process(int *fd, char **argv, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute_program(argv[2], envp);
}
