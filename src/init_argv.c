/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:34:23 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 16:22:04 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_argv(char *cmd)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	if (cmd == NULL)
		return (0);
	while (cmd[i] != '\0')
	{	
		if (is_whitespace(cmd[i]))
			i = skip_whitespace(cmd, i);
		else if (cmd[i] == '<' || cmd[i] == '>')
			i = skip_redirection(cmd, i);
		else
		{
			i = skip_arg(cmd, i);
			index += 1;
		}
	}
	return (index);
}

static char	**get_argv(char *cmd, int size)
{
	char	**argv;
	int		index;
	int		i;

	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (argv == NULL)
		print_error_exit("\n");
	index = 0;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (is_whitespace(cmd[i]))
			i = skip_whitespace(cmd, i);
		else if (cmd[i] == '<' || cmd[i] == '>')
			i = skip_redirection(cmd, i);
		else
		{
			argv[index] = get_arg(cmd, i);
			i = skip_arg(cmd, i);
			if (argv[index] != NULL)
				index++;
		}
	}
	argv[index] = NULL;
	return (argv);
}

static char	**ft_join_strvec(char **strvec1, char **strvec2)
{
	int		index;
	int		i;
	char	**argv;

	index = count_cmd(strvec1) + count_cmd(strvec2);
	argv = (char **)malloc_wrap(sizeof(char *) * (index + 1));
	i = 0;
	while (*strvec1)
	{
		argv[i] = *strvec1;
		i++;
		strvec1++;
	}
	while (*strvec2)
	{
		argv[i] = *strvec2;
		i++;
		strvec2++;
	}
	argv[i] = NULL;
	return (argv);
}

char	**init_argv(char *cmd)
{
	char	**argv;
	char	**inner_argv;
	char	**argv_temp;
	int		index;

	index = count_argv(cmd);
	argv_temp = get_argv(cmd, index);
	index = count_argv(argv_temp[0]);
	if (index > 1)
	{
		inner_argv = get_argv(argv_temp[0], index);
		argv = ft_join_strvec(inner_argv, argv_temp + 1);
		free(inner_argv);
		free(argv_temp[0]);
		free(argv_temp);
	}
	else
		argv = argv_temp;
	return (argv);
}
