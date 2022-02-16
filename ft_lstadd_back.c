/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:43:34 by pmoreno-          #+#    #+#             */
/*   Updated: 2021/09/29 09:44:14 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_back(t_comm_path **lst, t_comm_path *new)
{
	if (new == NULL)
		return ;
	new->ok = 1;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
		ft_lstlast(*lst)->next = new;
}
