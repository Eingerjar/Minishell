/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:03:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:14:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

t_flist	**pre_heredoc(char **chunks, int height, int *heredocnum)
{
	t_flist	**ret;
	int		i;

	i = 0;
	init_flist(&ret, height);
	while (i < height)
	{
		make_heredoc(chunks[i], &ret[i], heredocnum);
		i++;
	}
	return (ret);
}
