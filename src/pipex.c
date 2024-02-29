/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:51 by ampjimen          #+#    #+#             */
/*   Updated: 2024/02/26 15:46:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	child_process_start(int *fd, char **argv, char **envp)
{
	int		fd_infile;
	char	*path;
	char	**arg_cmd;

	close(fd[FD_READ_END]);
	fd_infile = open (argv[1], O_RDONLY);
	check_fd(fd_infile, argv[1]);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[FD_WRITE_END], STDOUT_FILENO);
	close(fd[FD_WRITE_END]);
	arg_cmd = ft_split(argv[2], ' ');
	get_path(arg_cmd[0], envp, &path);
	if (execve(path, arg_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(arg_cmd[0], 2);
		free_matrix(arg_cmd);
		free(path);
		exit(0);
	}
}

static	void	child_process_end(int *fd, char **argv, char **envp)
{
	int		fd_outfile;
	char	*path;
	char	**arg_cmd;

	close(fd[FD_WRITE_END]);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
	dup2(fd[FD_READ_END], STDIN_FILENO);
	close(fd[FD_READ_END]);
	dup2(fd_outfile, STDOUT_FILENO);
	arg_cmd = ft_split(argv[2], ' ');
	get_path(arg_cmd[0], envp, &path);
	if (execve(path, arg_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(arg_cmd[0], 2);
		free_matrix(arg_cmd);
		free(path);
		exit(0);
	}
}

/*void	leaks(void)
{
	system("leaks -q pipex");
}*/

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	check_argv(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
	{
		printf("aquí entra el proceso hijo 1º DEL IF, con su PID %d\n", getpid());
		child_process_start(fd, argv, envp);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error");
		if (pid == 0)
		{
			printf("Aquí entra el proceso del segundo  hijo del ELSE, con su PID %d\n", getpid());
			child_process_end(fd, argv, envp);
		}
		printf("este sería e proceso padre pid %d\n", getpid());
		close(fd[FD_READ_END]);
		close(fd[FD_WRITE_END]);
	}
	waitpid(pid, NULL, 0);
	//atexit(leaks);
	return (0);
}
