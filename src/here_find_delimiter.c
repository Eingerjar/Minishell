/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_find_delimiter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:56:43 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:56:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

t_flist	*find_delimiter(int **cmd, t_flist **heredoc)
{
	t_flist	*temp;
	int		i;
	int		j;

	while (TRUE)
	{
		i = (*cmd)[0];
		if (heredoc[i]->next == NULL)
		{
			(*cmd)[0] += 1;
		}
		else
		{
			temp = heredoc[i]->next;
			break ;
		}
	}
	j = 0;
	while (j < (*cmd)[1])
	{
		temp = temp->next;
		j++;
	}
	return (temp);
}
