/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:45:18 by ampjimen          #+#    #+#             */
/*   Updated: 2024/02/26 15:45:22 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define	FD_WRITE_END	1
# define	FD_READ_END		0

/* Search path*/

void	get_path(char *cmd, char *envp[], char **f_path);

/* Utils */

void	free_matrix(char **matrix);
void	check_argv(int argc);
void	check_fd(int fd, char *file);

#endif
