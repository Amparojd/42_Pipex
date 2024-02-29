/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:55:21 by ampjimen          #+#    #+#             */
/*   Updated: 2024/02/26 19:55:21 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	check_argv(int argc)
{
	if (argc != 5)
	{
		printf("Arguments: The number of arguments is not valid\n");
		printf("Try: ./pipex infile cmd1 cmd2 outfile\n");
		exit(0);
	}
}

void	check_fd(int fd, char *file)
{
	if (fd == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
		exit(0);
	}
}
