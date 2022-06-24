/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:34:23 by cgim              #+#    #+#             */
/*   Updated: 2022/06/24 11:49:31 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_argv(char *cmd)
{
	int	index;
	int	i;

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
			index++;
		}
	}
	return (argv);
}

char	**init_argv(char *cmd)
{
	char	**argv;
	int		index;

	index = count_argv(cmd);
	argv = get_argv(cmd, index);
	argv[index] = NULL;
	return (argv);
}
