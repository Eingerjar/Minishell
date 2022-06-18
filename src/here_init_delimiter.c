/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_init_delimiter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:58:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:58:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

void	init_delimiter(int **cmd, t_flist **heredoc)
{
	while (TRUE)
	{
		if (heredoc[(*cmd)[0]]->next == NULL)
			(*cmd)[0] += 1;
		else
			break ;
	}
}
