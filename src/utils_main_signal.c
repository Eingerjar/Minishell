/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:37:16 by haryu             #+#    #+#             */
/*   Updated: 2022/06/27 02:48:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_logic.h"

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
	ft_putstr_fd(temp2[0], STDOUT_FILENO);
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
