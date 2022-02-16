/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:42:16 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/02/11 15:42:19 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_envp_path(char **envp, int argc)
{
	int	i;

	i = 0;
	while (envp != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (&envp[i][argc]);
		i++;
	}
	return (0);
}

void	ft_add_path(char **l_paths, char *argv, t_comm_path **aux_l)
{
	int			j;
	char		*aux;
	char		*aux_p;
	t_comm_path	*var;
	int			i;

	j = 0;
	i = -1;
	var = malloc(sizeof(t_comm_path));
	while (l_paths[j] != 0)
	{
		aux = ft_strjoin(l_paths[j], "/");
		aux_p = ft_strjoin(aux, argv);
		var->comm = ft_split(aux_p, ' ');
		var->next = 0;
		i = access(var->comm[0], X_OK);
		if (i == 0)
		{
			var->ok = 1;
			ft_lstadd_back(aux_l, var);
			return ;
		}
		j++;
	}
	ft_lstadd_back(aux_l, var);
	ft_comm_error(argv);
	var->ok = 0;
}

t_comm_path	**ft_accesslist(char **l_paths, char **argv, int argc)
{
	int			i;
	t_comm_path	**aux_l;
	t_comm_path	*var;
	int			co;

	i = 2;
	l_paths += 0;
	aux_l = malloc(sizeof(t_comm_path *));
	*aux_l = 0;
	while (i < argc - 1)
	{
		var = malloc(sizeof(t_comm_path));
		co = access(argv[i], X_OK);
		if (co == 0)
		{
			var->comm = ft_split(argv[i], ' ');
			var->ok = 1;
			var->next = 0;
			ft_lstadd_back(aux_l, var);
		}
		else
			ft_add_path(l_paths, argv[i], aux_l);
		i++;
	}
	return (aux_l);
}

void	ft_open_infile(char *arc)
{
	int	fd;

	fd = open(arc, O_RDONLY);
	if (fd < 0)
		ft_file_error(arc);
	close(fd);
}

void	ft_open_outfile(char *arc)
{
	int	fd;

	fd = open(arc, O_CREAT | O_WRONLY, 0666);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	char		*path;
	char		**l_paths;
	int			fd;
	t_comm_path	**comm_dir;

	if (argc == 5)
	{
		path = ft_envp_path(envp, argc);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_file_error(argv[1]);
		close(fd);
		fd = open(argv[4], O_CREAT | O_WRONLY, 0666);
		close(fd);
		l_paths = ft_split(path, ':');
		comm_dir = ft_accesslist(l_paths, argv, argc);
		ft_command_validation(comm_dir, argv);
		ft_first_part(comm_dir[0], envp, argv);
		ft_check_errors(comm_dir);
	}
	else
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		exit(1);
	}
	return (0);
}
