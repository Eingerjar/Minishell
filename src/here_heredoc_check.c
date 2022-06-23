/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_heredoc_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:33:56 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	heredoc_check(char *line, char *installed)
{
	char	**chunks;
	int		chunk_height;
	t_flist	**heredoc;
	int		heredocnum;

	chunks = vertical_split(line);
	chunk_height = check_height(line);
	heredocnum = 0;
	heredoc = pre_heredoc(chunks, chunk_height, &heredocnum);
	if (heredocnum != 0)
		fork_heredoc(heredoc, chunk_height, installed);
	free_heredoc(heredoc, chunk_height);
	chunk_free(chunks, chunk_height);
	if (g_global.last_exitcode != 0)
		return (TRUE);
	return (FALSE);
}
