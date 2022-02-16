/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:41:53 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/02/11 15:41:58 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile(int fd, int fd1[2])
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fd1[1], STDOUT_FILENO);
	close(fd1[1]);
}

void	ft_first_child(char **argv, int fd1[2], t_comm_path *act, char **envp)
{
	int	fd;

	close(fd1[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	ft_infile(fd, fd1);
	if (execve(act->comm[0], act->comm, envp) < 0)
		exit (127);
}

void	ft_first_part(t_comm_path *act, char **envp, char **argv)
{
	int			fd1[2];
	int			status;
	int			pid;

	pipe(fd1);
	pid = fork();
	if (pid == -1)
		perror("Error");
	else if (pid == 0)
		ft_first_child(argv, fd1, act, envp);
	else
	{
		act = act->next;
		ft_second_part(act, fd1, argv, envp);
	}
	wait(&status);
	wait(&status);
}

void	ft_second_part(t_comm_path *act, int fd1[2], char **argv, char **envp)
{
	int		fd;
	int		pid;

	close(fd1[1]);
	pid = fork();
	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		exit (0);
	if (pid == -1)
		perror("Error");
	else if (pid == 0)
	{
		dup2(fd1[0], STDIN_FILENO);
		close(fd1[0]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		if (execve(act->comm[0], act->comm, envp) < 0)
			exit (127);
	}
	else
	{
		close(fd1[0]);
		close(fd);
	}
}
