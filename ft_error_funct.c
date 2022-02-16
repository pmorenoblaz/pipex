/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:54:00 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/02/12 16:54:04 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_file_error(char *str)
{
	ft_putstr_fd(strerror(errno), 2);
	write(2, ": ", 2);
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
}

void	ft_comm_error(char *str, t_comm_path *var)
{
	char	**s;

	var->ok = 0;
	s = ft_split(str, ' ');
	ft_putstr_fd("command not found", 2);
	write(2, ": ", 2);
	ft_putstr_fd(s[0], 2);
	write(2, "\n", 1);
}

void	ft_check_errors(t_comm_path **comm_dir)
{
	t_comm_path	*var;

	var = comm_dir[0];
	if (var->next->ok == 0)
		exit (127);
}

void	ft_command_validation(t_comm_path **comm_dir, char **argv)
{
	t_comm_path	*var;

	var = comm_dir[0];
	if (var->comm == NULL)
	{
		if (var->next->comm == NULL)
			exit (127);
		else
			var->comm = ft_split(argv[2], ' ');
	}
	else
		if (var->next->comm == NULL)
			var->next->comm = ft_split(argv[3], ' ');
}
