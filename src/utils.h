/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:08 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/30 16:57:52 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <unistd.h>

void	error_message(char *message);
int		open_file(char *file, int flags, mode_t mode);
void	close_file(int fd);
char	**split_command(char *command);
int		count_words(char *str);

#endif /* UTILS_H */