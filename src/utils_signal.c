/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:37:16 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 12:56:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handler_main(int signum)
{
	char	*temp;
	char	**temp2;

	temp = current_prompt();
	temp2 = ft_split(temp, '>');
	if (signum == SIGQUIT)
	{
		printf("%s", temp2[0]);
		free(temp);
		free(temp2);
		rl_replace_line("\n", 0);
		return ;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (g_global.last_exitcode != 130)
		ft_putstr_fd(temp2[0], 1);
	free(temp);
	free(temp2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	main_signal(void)
{
	signal(SIGINT, handler_main);
	signal(SIGQUIT, handler_main);
}

static void	handler_call_cmd(int signum)
{
	exit (128 + signum);
}

void	call_cmd_signal(void)
{
	signal(SIGINT, handler_call_cmd);
	signal(SIGQUIT, handler_call_cmd);
}
