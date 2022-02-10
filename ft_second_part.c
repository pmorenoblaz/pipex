#include "pipex.h"

void	ft_second_part(t_comm_path *act, char **envp, char **argv, int argc)
{
	int			proc;
	t_comm_path	*ant;
	// int			fd;
	char		*path;

	ant = act;
	act = ant->next;
	close(ant->fd[1]);
	pipe(act->fd);
	proc = fork();
	// fd = open(argv[argc - 1], O_CREAT, 0644);
	// printf("%s\n", argv[argc - 1]);
	// printf("%d\n", argc - 1);
	// printf("%d\n", fd);
	if (proc == 0)
	{
		// act->fd[1] = open(argv[argc - 1], O_WRONLY);
		// close(act->fd[0]);

		// dup2(ant->fd[0], STDIN_FILENO);
		// close(ant->fd[0]);
		// dup2(act->fd[1], STDOUT_FILENO);
		// close(act->fd[1]);

		// execve(act->comm[0], act->comm, envp);
	// }
	// else	
		ft_last_part(act, envp, argv, argc);
	}
}
