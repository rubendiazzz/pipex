/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:56 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/30 12:59:31 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"

void	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

int	open_file(char *file, int flags, mode_t mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd < 0)
		error_message("Error: Failed to open file\n");
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) < 0)
		error_message("Error: Failed to close file\n");
}

char	**split_command(char *command)
{
	char	**split;

	split = ft_split(command, ' ');
	if (!split)
		error_message("Error: Failed to split command\n");
	return (split);
}
