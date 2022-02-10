#include "pipex.h"

void	ft_last_part(t_comm_path *act, char **envp, char **argv, int argc)
{
	int			proc;
	int			fd;
	char		*path;

	pipe(act->fd);
	proc = fork();
	if (proc == 0)
	{
		close(act->fd[1]);
		fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);	
		dup2(act->fd[0], STDIN_FILENO);
		close(act->fd[0]);
		dup2(fd, STDOUT_FILENO);
		execve(act->comm[0], act->comm, envp);
	}
	close(fd);
	close(act->fd[0]);
	close(act->fd[1]);
}
