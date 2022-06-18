/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_init_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:35:59 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 11:57:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

void	prepare_pipe(int ***pipes, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (pipe((*pipes)[i]) == -1)
		{
			printf("Pipe error : %s\n", strerror(errno));
			g_global.last_exitcode = 1;
		}
		i++;
	}
	if (g_global.last_exitcode == 1)
		exit (1);
	return ;
}

int	**init_pipe(int cmdnum)
{
	int		**pipes;
	int		i;

	pipes = malloc_wrap(sizeof(int *) * cmdnum);
	i = -1;
	while (++i < cmdnum)
		pipes[i] = malloc_wrap(sizeof(int) * 2);
	prepare_pipe(&pipes, cmdnum);
	if (g_global.last_exitcode == 1)
		exit(1);
	return (pipes);
}
