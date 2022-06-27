/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:37:16 by haryu             #+#    #+#             */
/*   Updated: 2022/06/27 13:43:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_main(int signum)
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

void	handler_call_cmd(int signum)
{
	if (signum != SIGINT)
		return ;
	ft_putstr_fd("\b\b  \b\b\n", STDERR_FILENO);
}

void	call_cmd_signal(void)
{
	signal(SIGINT, handler_call_cmd);
	signal(SIGQUIT, handler_call_cmd);
}
