/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:58:29 by haryu             #+#    #+#             */
/*   Updated: 2022/06/17 22:01:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

void	free_heredoc_part(t_flist **heredoc)
{
	t_flist	*temp;
	t_flist	*next;

	while (TRUE)
	{
		temp = (*heredoc);
		if (temp->next == 0)
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
	int	i;

	i = height;
	while (--i >= 0)
	{
		if (heredoc[i]->next != 0)
			free_heredoc_part(&(heredoc[i]->next));
		free(heredoc[i]);
	}
	free(heredoc);
	return ;
}