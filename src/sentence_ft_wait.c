/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_ft_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:37:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 02:59:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_wait(pid_t *childs, int numbers, int builtin)
{
	int		index;
	int		stats;
	int		prev;

	index = -1;
	wait_signal();
	while (++index < numbers)
	{
		wait(&stats);
		if (builtin == 1 && numbers == 1)
			prev = g_global.last_exitcode;
		g_global.last_exitcode = WEXITSTATUS(stats);
		if (WIFSIGNALED(stats))
			g_global.last_exitcode = 128 + WTERMSIG(stats);
	}
	if (prev != 0 && builtin == 1 && numbers == 1 && !WIFSIGNALED(stat))
		g_global.last_exitcode = prev;
	free(childs);
	if (g_global.last_exitcode != 0)
		return (TRUE);
	return (FALSE);
}
