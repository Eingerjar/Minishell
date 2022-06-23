/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_init_pids.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:38:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:33:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	*init_pids(int numbers)
{
	pid_t	*pids;

	pids = malloc_wrap(sizeof(pid_t) * numbers);
	return (pids);
}
