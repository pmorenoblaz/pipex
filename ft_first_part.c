#include "pipex.h"

void	ft_first_part(t_comm_path **comm_dir, char **envp, char **argv, int argc)
{
	int			proc;
	int			fd;
	t_comm_path	*act;
	char		*path;

	act = comm_dir[0];
	pipe(act->fd);
	proc = fork();
	if (proc == -1)
		write(1, "Error en fork", 13);
	if (proc == 0)
	{
		close(act->fd[0]);
		fd = open(argv[1], O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(act->fd[1], STDOUT_FILENO);
		close(act->fd[1]);
		execve(act->comm[0], act->comm, envp);
	}
	else
	{
		close(act->fd[1]);
		close(act->fd[0]);
		close(fd);
		act = act->next;
		ft_last_part(act, envp, argv, argc);
		// ft_second_part(act, envp, argv, argc);
	}
}
