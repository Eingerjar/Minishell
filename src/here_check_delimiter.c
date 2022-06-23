/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_check_delimiter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:57:29 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:32:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_delimiter(int **cmd, t_flist *delimiter, \
t_flist **heredoc, int maxlen)
{
	if (delimiter->next == NULL)
	{
		(*cmd)[0] += 1;
		(*cmd)[1] = 0;
	}
	else
	{
		(*cmd)[1] += 1;
		return ;
	}
	if ((*cmd)[0] == maxlen)
		return ;
	while (heredoc[(*cmd)[0]]->next == NULL)
	{
		(*cmd)[0] += 1;
		if ((*cmd)[0] == maxlen)
			break ;
	}
}
