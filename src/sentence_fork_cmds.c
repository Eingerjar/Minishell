/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_fork_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:46:05 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 21:38:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
			call_cmd(index, chunks[index], pipes);
	}
	close_pipe(pipes, height - 1);
	if (ft_wait(childs, height))
		return (TRUE);
	return (FALSE);
}
