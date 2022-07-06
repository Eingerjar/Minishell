/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_open.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:05:41 by cgim              #+#    #+#             */
/*   Updated: 2022/07/04 23:08:16 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	w_open(const char *path, int flags)
{
	int	fd;

	fd = open(path, flags, 0644);
	if (fd == -1)
	{
		ft_putstr_fd((char *)path, 2);
		perror(" \b");
		exit(1);
	}
	return (fd);
}
