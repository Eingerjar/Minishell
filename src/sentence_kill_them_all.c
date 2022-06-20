/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_kill_them_all.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:45:50 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:03:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

int	kill_them_all(pid_t *childs, int numbers)
{
	int	index;

	index = -1;
	while (++index < numbers)
		kill(childs[index], SIGKILL);
	return (FALSE);
}
