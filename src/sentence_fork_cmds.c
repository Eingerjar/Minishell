/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_fork_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:46:05 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 21:35:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	fake_process(void)
{
	usleep(300);
	exit(0);
}

static void	builtin_process(pid_t **child, char	**chunks, \
t_chunk *chunk, int **pipes)
{
	(*child)[0] = fork();
	if ((*child)[0] == 0)
		fake_process();
	else
		call_cmd(0, chunks, chunk, pipes);
}

int	fork_cmds(int height, char **chunks, int **pipes)
{
	pid_t		*childs;
	t_chunk		*chunk;
	int			index;

	childs = init_pids(height);
	index = -1;
	while (++index < height)
	{
		chunk = init_structure(index, chunks);
		if (height == 1 && is_builtin(chunk) && \
				index == 0 && !builtin_pro_or_not(chunk->argv))
			builtin_process(&childs, chunks, chunk, pipes);
		else
			childs[index] = fork();
		if (childs[index] == 0)
			call_cmd(index, chunks, chunk, pipes);
		free_t_chunk(chunk);
	}
	close_pipe(pipes, height - 1);
	if (ft_wait(childs, height, !builtin_pro_or_not(chunks)))
		return (TRUE);
	return (FALSE);
}
