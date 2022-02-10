#include "pipex.h"

void	ft_first_pipe(t_comm_path **comm_dir, char **envp, char **argv)
{
	int fd1[2], fd, fd3;
    int status, pid;
	t_comm_path	*act;
	char	**arg1;

	act = comm_dir[0];
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		arg1 = ft_split(argv[2], ' ');
		fd3 = open(argv[1], O_RDONLY);
		dup2(fd3, STDIN_FILENO);
		close(fd3);
		close(fd1[0]);
		dup2(fd1[1], STDOUT_FILENO);
		close(fd1[1]);
		execve(act->comm[0], act->comm, envp);
	}
	else
	{
		close(fd1[1]);
		pid = fork();
		fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (pid == 0)
		{
			act = act->next;
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
	wait(&status);
	wait(&status);
}
