/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_fork_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:43:02 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:08:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

void	fork_heredoc(t_flist **heredoc, int height, char *installed)
{
	pid_t	here_child;
	int		status;

	here_child = fork();
	if (here_child == -1)
		printf("%sfork error\n", RED);
	if (here_child == 0)
		child_heredoc(heredoc, height, installed);
	else
		wait(&status);
	g_global.last_exitcode = WEXITSTATUS(status);
	return ;
}
