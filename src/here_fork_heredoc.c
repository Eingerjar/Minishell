/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_fork_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:43:02 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 03:40:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fork_heredoc(t_flist **heredoc, int height, char *installed, int prev)
{
	pid_t	here_child;
	int		status;

	wait_signal();
	here_child = fork();
	if (here_child == -1)
		printf("%sfork error\n", RED);
	if (here_child == 0)
		child_heredoc(heredoc, height, installed, prev);
	else
		wait(&status);
	g_global.last_exitcode = WEXITSTATUS(status);
	return ;
}
