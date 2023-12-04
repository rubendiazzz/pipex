/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:56:53 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/04 15:28:43 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"
#include "../libft/libft.h"

char	*get_command_path(char *cmd)
{
	char	**path_dirs;
	char	*path;
	char	*cmd_path;
	int		i;

	path = getenv("PATH");
	path_dirs = ft_split(path, ':');
	i = 0;
	while (path_dirs[i])
	{
		cmd_path = ft_strjoin(path_dirs[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

void	execute_command(char **cmd)
{
	char	*cmd_path;

	cmd_path = get_command_path(cmd[0]);
	if (!cmd_path)
	{
		perror("Error finding command");
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, cmd, NULL) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}

void	child_process(int fd[], char **cmd1, char *file1)
{
	int	infile;

	infile = open(file1, O_RDONLY);
	if (infile == -1)
	{
		perror("Error opening infile");
		exit(EXIT_FAILURE);
	}
	if (dup2(infile, 0) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (close(fd[0]) == -1 || close(infile) == -1)
	{
		perror("Error closing file descriptor");
		exit(EXIT_FAILURE);
	}
	execute_command(cmd1);
}

void	parent_process(int fd[], char **cmd2, char *file2)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Error opening outfile");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], 0) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, 1) == -1)
	{
		perror("Error duplicating file descriptor");
		exit(EXIT_FAILURE);
	}
	if (close(fd[1]) == -1 || close(outfile) == -1)
	{
		perror("Error closing file descriptor");
		exit(EXIT_FAILURE);
	}
	execute_command(cmd2);
}

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creating pipe");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating child process");
		return (1);
	}
	if (pid == 0)
		child_process(fd, ft_split(argv[2], ' '), argv[1]);
	else
		parent_process(fd, ft_split(argv[3], ' '), argv[4]);
	return (0);
}
