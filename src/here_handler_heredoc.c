/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_handler_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:08:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:08:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

void	handler_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	g_global.last_exitcode = 1;
	exit(TRUE);
}
