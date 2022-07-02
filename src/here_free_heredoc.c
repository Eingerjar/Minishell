/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_free_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:58:29 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 21:20:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_heredoc_part(t_flist **heredoc)
{
	t_flist	*temp;
	t_flist	*next;

	while (TRUE)
	{
		temp = (*heredoc);
		if (temp == 0)
			break ;
		next = temp->next;
		(*heredoc) = next;
		free(temp->name);
		free(temp);
		temp = 0;
	}
}

void	free_heredoc(t_flist **heredoc, int height)
{
	int		i;

	i = -1;
	while (++i < height)
	{
		free_heredoc_part(&heredoc[i]);
		free(heredoc[i]);
	}
	free(heredoc);
	return ;
}
