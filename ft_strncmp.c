/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:12:32 by pmoreno-          #+#    #+#             */
/*   Updated: 2021/09/21 18:20:02 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((a[i] != 0) && (i < n))
	{
		if (a[i] != b[i] || i == n - 1)
			return (a[i] - b[i]);
		i++;
	}
	if (a[i] == 0 && b[i] != 0 && i < n)
		return (-b[i]);
	return (0);
}
