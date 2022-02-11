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

void	ft_first_pipe(t_comm_path	*act, char **envp, char **argv)
{
	int			fd1[2];
	int			fd;
	int			status;
	int			pid;
	char		**arg1;

	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		arg1 = ft_split(argv[2], ' ');
		fd = open(argv[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		close(fd1[0]);
		dup2(fd1[1], STDOUT_FILENO);
		close(fd1[1]);
		execve(act->comm[0], act->comm, envp);
	}
	else
		ft_second_part(act->next, fd1, argv, envp);
	wait(&status);
	wait(&status);
}

void	ft_second_part(t_comm_path *act, int fd1[2], char **argv, char **envp)
{
	int		fd;
	int		pid;
	char	**arg1;

	close(fd1[1]);
	pid = fork();
	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (pid == 0)
	{
		arg1 = ft_split(argv[3], ' ');
		dup2(fd1[0], STDIN_FILENO);
		close(fd1[0]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(act->comm[0], act->comm, envp);
	}
	else
	{
		close(fd1[0]);
		close(fd);
	}
}
