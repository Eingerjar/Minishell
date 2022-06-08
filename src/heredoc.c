/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:25:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/08 18:33:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	global;

static void	handler_heredoc(int signum)
{
	return ;
}

static int check_double_bracket(char **chunks, int height)
{
	return (FALSE);
}

int heredoc(char **chunks, int height)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, handler_heredoc);
	pid = fork();
	if (pid == 0)
	{
		check_double_bracket(chunks, height);
		exit(0);
	}
	else
		wait(&status);
	if (!WIFEXITED(status))
	{
		global.last_exitcode = WEXITSTATUS(status);
		return (FALSE);
	}
	global.last_exitcode = 0;
	return (TRUE);
}
