/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_open.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:02:09 by cgim              #+#    #+#             */
/*   Updated: 2022/07/04 23:09:42 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	r_open(const char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd == -1)
	{
		ft_putstr_fd((char *)path, 2);
		perror(" \b");
		exit(1);
	}
	return (fd);
}
