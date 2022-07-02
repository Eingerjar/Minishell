/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_pre_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 11:24:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (is_whitespace(line[i]))
			continue ;
		else if (line[i] == 60 || line[i] == 62)
			i = check_redirection(line, i, line[i]);
		else if (line[i] == 124)
			i = check_pipe(line, i);
		else if (line[i] == 59 || line[i] == 44 || \
line[i] == 92 || line[i] == 38)
			i = line[i] * -1;
		else
			i = check_command(line, i);
		if (i < 0)
			return (print_syntex_error(i));
		else if (!line[i])
			break ;
	}
	return (FALSE);
}

static int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_whitespace(line[i]))
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	pre_error_check(char *line)
{
	int	error;

	error = 0;
	if (ft_strlen(line) == 0)
		error = 1;
	if (is_empty(line))
		error = 1;
	if (check_line(line))
		error = 1;
	if (error == 1)
	{
		g_global.last_exitcode = 1;
		return (TRUE);
	}
	return (FALSE);
}
