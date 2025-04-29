/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:30:53 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/29 14:32:12 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

// execute_utils.c
void	exec_parent_process(int *fd, char **argv, char **envp);
void	exec_child_process(int *fd, char **argv, char **envp);
void	execute_program(char *argv, char **envp);
// pipex_utils.c
void	error(void);
void	free_split(char **split);
void	free_execve(char **command, char *command_path);
#endif
