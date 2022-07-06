/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_handler_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:08:21 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 03:24:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_heredoc(int signum)
{
	if (signum == SIGQUIT)
	{
		return ;
	}
	exit(1);
}
