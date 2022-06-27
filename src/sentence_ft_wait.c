/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_ft_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:37:27 by haryu             #+#    #+#             */
/*   Updated: 2022/06/27 13:39:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_wait(pid_t *childs, int numbers)
{
	int		index;
	int		stats;

	index = -1;
	(void)childs;
	wait_signal();
	while (++index < numbers)
	{
		wait(&stats);
		g_global.last_exitcode = WEXITSTATUS(stats);
		if (WIFSIGNALED(stats))
			g_global.last_exitcode = 128 + WTERMSIG(stats);
	}
	if (g_global.last_exitcode != 0)
		return (TRUE);
	return (FALSE);
}
