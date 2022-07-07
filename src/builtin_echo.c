/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:19 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 17:41:37 by haryu            ###   ########.fr       */
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
	int	i;

	i = 0;
	if (max == 1)
		return (FALSE);
	else if (argv[1][0] == '-')
	{
		i = 1;
		while (argv[1][i])
		{
			if (argv[1][i] != 'n')
				return (FALSE);
			i++;
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	check_is_flag(char *str, int *flag, int *other, int first)
{
	int	i;

	i = 1;
	if (*other == TRUE)
		return (FALSE);
	if (str[0] != '-')
	{
		*other = TRUE;
		return (FALSE);
	}
	while (str[i])
	{
		if (str[i] != 'n')
		{
			*other = TRUE;
			return (FALSE);
		}
		i++;
	}
	(*flag) = 1;
	if (!first)
		return (FALSE);
	return (TRUE);
}

void	builtin_echo(char **argv)
{
	int	i;
	int	max;
	int	other;
	int	flag;
	int	first;

	i = 0;
	max = echo_argv_length(argv);
	flag = check_flag(max, argv);
	if ((max == 1 || (max == 2 && flag == TRUE)) && no_argument(flag))
		return ;
	init_echo_flags(&flag, &first, &other);
	while (++i < max)
	{
		if (check_is_flag(argv[i], &flag, &other, first))
			continue ;
		else
			write(1, argv[i], ft_strlen(argv[i]));
		if (i + 1 == max && echo_print_nl(flag))
			break ;
		write(1, " ", 1);
	}
	g_global.last_exitcode = 0;
	return ;
}
