/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:56:53 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/30 15:00:48 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include "../libft/libft.h"

void	execute_command(char **cmd)
{
	execve(cmd[0], cmd, NULL);
}

void	child_process(int fd[], char **cmd1)
{
	dup2(fd[1], 1);
	close(fd[0]);
	execute_command(cmd1);
}

void	parent_process(int fd[], char **cmd2)
{
	dup2(fd[0], 0);
	close(fd[1]);
	execute_command(cmd2);
}

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;

	if (argc != 5)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	pipe(fd);
	pid = fork();
	if (pid == 0)
		child_process(fd, cmd1);
	else
		parent_process(fd, cmd2);
	return (0);
}
