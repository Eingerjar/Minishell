/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_t_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:45:45 by cgim              #+#    #+#             */
/*   Updated: 2022/06/25 11:15:35 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	free_t_flist(t_flist *flist)
{
	t_flist	*tmp;

	if (flist == NULL)
		return ;
	while (flist)
	{
		tmp = flist;
		if (flist->name != NULL)
			free(flist->name);
		flist = flist->next;
		free(tmp);
	}
}

void	free_t_chunk(t_chunk *chunk)
{
	int	i;

	if (chunk == NULL)
		return ;
	if (chunk->argv != NULL)
	{
		i = -1;
		while (chunk->argv[++i])
			free(chunk->argv[i]);
		free(chunk->argv);
	}
	if (chunk->input != NULL)
		free_t_flist(chunk->input);
	if (chunk->output != NULL)
		free_t_flist(chunk->output);
	free(chunk);
}
