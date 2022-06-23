/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_pre_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:03:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
