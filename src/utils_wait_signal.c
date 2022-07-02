/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wait_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:37:02 by haryu             #+#    #+#             */
/*   Updated: 2022/06/27 13:38:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_wait(int signum)
{
	(void)signum;
	return ;
}

void	wait_signal(void)
{
	signal(SIGINT, handler_wait);
	signal(SIGQUIT, handler_wait);
}
