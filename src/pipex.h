/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:07:21 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/30 13:01:52 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "utils.h"

/* Function to handle errors */
void	error_handler(int err_code);

/* Function to open files */
int		open_file(char *file, int flags, mode_t mode);

/* Function to close files */
void	close_file(int fd);

/* Function to execute shell commands */
void	execute_command(char **cmd);

#endif /* PIPEX_H */