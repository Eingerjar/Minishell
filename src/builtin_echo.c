/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 16:05:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	echo_argv_length(char **argv)
{
	int	i;

	i = 1;
	while(argv[i])
	{
		i++;
	}
	return (i);
}

void	builtin_echo(char **argv)
{
	int	i;
	int	max;

	i = 1;
	max = echo_argv_length(argv);
	while (i < max)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (i + 1 == max)
			break ;
		write(1, " ", 1);
	}
	return ;
}
