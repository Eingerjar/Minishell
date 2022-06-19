/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_fork_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:46:05 by haryu             #+#    #+#             */
/*   Updated: 2022/06/19 16:58:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

int	fork_cmds(int height, char **chunks, int **pipes)
{
	pid_t	*childs;
	int		index;

	childs = init_pids(height);
	index = -1;
	while (++index < height)
	{
		childs[index] = fork();
		if (childs[index] != 0)
			continue ;
		else if (childs[index] == 0)
		{
			childs_test(height, chunks, pipes);
			//builtin_test(height, chunks, pipes);
		}
	}
	close_pipe(pipes, height);
	if (ft_wait(childs, height))
		return (TRUE);
	return (FALSE);
}
