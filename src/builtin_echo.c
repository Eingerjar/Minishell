/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 13:37:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	echo_argv_length(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static int	no_argument(int flag)
{
	if (flag == TRUE)
		;
	else
		write(1, "\n", 1);
	g_global.last_exitcode = 0;
	return (TRUE);
}

static int	check_flag(int max, char **argv)
{
	if (max == 1)
		return (FALSE);
	else
		return (!ft_strncmp(argv[1], "-n", 2));
}

void	builtin_echo(char **argv)
{
	int	i;
	int	max;
	int	flag;

	i = 0;
	max = echo_argv_length(argv);
	flag = check_flag(max, argv);
	if ((max == 1 || (max == 2 && flag == TRUE)) && no_argument(flag))
		return ;
	while (++i < max)
	{
		if (i == 1 && flag == TRUE)
			continue ;
		write(1, argv[i], ft_strlen(argv[i]));
		if (i + 1 == max)
		{
			if (flag == FALSE)
				write(1, "\n", 1);
			break ;
		}
		write(1, " ", 1);
	}
	g_global.last_exitcode = 0;
	return ;
}
