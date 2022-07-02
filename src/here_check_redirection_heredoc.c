/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_check_redirection_heredoc.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:10:06 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:30:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_redirection_heredoc(char *line, int index, \
t_flist **target, int *heredocnum)
{
	int	priv;
	int	next;

	next = 0;
	if (line[index] == 60 && line[index + 1] == 60)
	{
		index += 2;
		while (line[index] == ' ')
			index++;
		priv = index;
		next = check_command(line, priv);
		make_flist(priv, next, line, target);
		*heredocnum += 1;
	}
	else
		return (check_redirection(line, index, line[index]));
	return (next);
}
