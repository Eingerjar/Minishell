/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_kill_them_all.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:45:50 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:33:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	kill_them_all(pid_t *childs, int numbers)
{
	int	index;

	index = -1;
	while (++index < numbers)
		kill(childs[index], SIGKILL);
	return (FALSE);
}
