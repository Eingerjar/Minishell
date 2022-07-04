/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:42:19 by haryu             #+#    #+#             */
/*   Updated: 2022/07/04 17:07:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_numeric_arg(char	*argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (i == 0 && argv[i] == '-')
		{
			if (!ft_isdigit(argv[i + 1]))
				return (FALSE);
			else
				continue ;
		}
		if (!ft_isdigit(argv[i]))
			return (FALSE);
	}
	return (TRUE);
}

void	error_print(int code, char *argv)
{
	char	*error;

	error = "WELCHS > exit : ";
	write(2, "😥 exit\n", ft_strlen("😥 exit\n"));
	write(2, error, ft_strlen(error));
	write(2, argv, ft_strlen(argv));
	if (code == 1)
	{
		write(2, " : numeric argument reqired\n", \
				ft_strlen(" : numeric argument reqired\n"));
		exit(255);
	}
	else
	{
		write(2, " : too many arguments\n", \
				ft_strlen(" : too many arguments\n"));
		g_global.last_exitcode = 1;
		return ;
	}
}

static void	exit_with_arg(char **argv)
{
	long long	exitcode;

	exitcode = 0;
	if (argv[1])
	{
		if (ft_strlen(argv[1]) > 19)
		{
			if (argv[1][0] != '-')
			{
				error_print(1, argv[1]);
				return ;
			}
		}
		if (ft_strtol(&exitcode, argv[1]))
			error_print(1, argv[1]);
	}
	printf("😴 exit\n");
	exit((unsigned int)exitcode);
}

void	builtin_exit(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (i == 2)
		{
			error_print(2, argv[i]);
			return ;
		}
		if (!is_numeric_arg(argv[i]))
			error_print(1, argv[i]);
	}
	exit_with_arg(argv);
}
