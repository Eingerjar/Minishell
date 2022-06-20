/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_ft_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:37:27 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 11:57:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

int	ft_wait(pid_t *childs, int numbers)
{
	int		index;
	int		stats;
	int		kill_flag;
	pid_t	temp;

	index = -1;
	kill_flag = 0;
	while (++index < numbers)
	{
		temp = wait(&stats);
		if (WEXITSTATUS(stats) != 0 && kill_flag == 0)
		{
			kill_them_all(childs, numbers);
			kill_flag++;
			(void)temp;
		}
	}
	g_global.last_exitcode = WEXITSTATUS(stats);
	if (kill_flag != 0)
		return (TRUE);
	return (FALSE);
}
