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

#include "../../include/pipex.h"

static void	execute(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
	{
		free_matrix(argv);
		free(path);
		exit_error(ERROR_EXE);
	}
}

static void	start_child_process(int *fd, char **argv, char **envp)
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
	execute(path, arg_cmd, envp);
}

static	void	end_child_process(int *fd, char **argv, char **envp)
{
	int		fd_outfile;
	char	*path;
	char	**arg_cmd;

	close(fd[FD_WRITE_END]);
	// if (access(argv[4], R_OK | W_OK) != 0)
	// 	exit_error(ERROR_EXE);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
	// if (fd_outfile == -1)
	// 	exit_error(ERROR_EXE);
	dup2(fd[FD_READ_END], STDIN_FILENO);
	close(fd[FD_READ_END]);
	dup2(fd_outfile, STDOUT_FILENO);
	arg_cmd = ft_split(argv[3], ' ');
	get_path(arg_cmd[0], envp, &path);
	if (arg_cmd[0][0] == '/')
		execute(arg_cmd[0], arg_cmd, envp);
	else
		execute(path, arg_cmd, envp);
}

void	leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	check_argv(argc);
	pipe(fd);
	if(pipe(fd) < 0)
		exit_error(ERROR_PIP);
	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FRK);
	if (pid == 0)
		start_child_process(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid == -1)
			exit_error(ERROR_FRK);
		if (pid == 0)
			end_child_process(fd, argv, envp);
		close(fd[FD_READ_END]);
		close(fd[FD_WRITE_END]);
	}
	waitpid(pid, NULL, 0);
	atexit(leaks);
	return (0);
}