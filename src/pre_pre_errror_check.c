/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/20 12:36:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line(char *line)
{
	int	i;
	int	max;

	i = -1;
	max = (int)ft_strlen(line);
	while (++i < max)
	{
		if (line[i] == ' ')
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
		else if (i >= max)
			break ;
	}
	return (FALSE);
}

int	pre_error_check(char *line)
{
	if (check_line(line))
		return (TRUE);
	return (FALSE);
}
