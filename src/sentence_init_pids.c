/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_init_pids.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:38:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 06:00:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	*init_pids(int numbers)
{
	pid_t	*pids;

	pids = malloc_wrap(sizeof(pid_t) * numbers);
	ft_memset(pids, 1, sizeof(pid_t) * numbers);
	return (pids);
}
