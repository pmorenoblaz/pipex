#include "pipex.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	first_child(int *fd1, char **argv, char **envp, t_comm_path *act)
{
	int			fd;
	char		**arg1;
	char		*path;

write(1, "hola\n", 5);
	arg1 = ft_split(argv[2], ' ');
	path = act->comm[0];
	// ft_lstprint(comm_dir);
	close(fd1[0]);
	fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	// 	ft_fd_error(argv[1]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fd1[1], STDOUT_FILENO);
	close(fd1[1]);
	execve(path, arg1, envp);
		// exit(127);
}

void	second_child(int fd1, char **argv, char **envp, t_comm_path *act)
{
	int		fd;
	char	**arg2;
	char	*path;

write(1, "hola\n", 5);
	
	//ft_putstr(comm_dir[1]->comm[0]);
	arg2 = ft_split(argv[3], ' ');
		//ft_lstprint(comm_dir);
	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	// if (fd == -1)
	// 	ft_fd_error(argv[4]);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	dup2(fd, STDOUT_FILENO);
	execve(path, arg2, envp);
		// exit
}

int	ft_pipex(char **argv, char **envp, t_comm_path **comm_dir)
{
	int			fd1[2];
	int			status;
	int			pid;
	t_comm_path *act;

	act = comm_dir[0];
	pipe(fd1);
	pid = fork();
	if (pid == -1)
		perror("Error");
	else if (pid == 0)
		first_child(fd1, argv, envp, act);
	else
	{
		close(fd1[1]);
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			act = act->next;
			second_child(fd1[0], argv, envp, act);
		}
		else
			close(fd1[1]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
