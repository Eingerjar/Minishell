/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_handler_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:08:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	g_global.last_exitcode = 1;
	exit(TRUE);
}
