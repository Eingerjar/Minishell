/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_chunk_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:22:28 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:00:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	chunk_free(char **chunk, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
		free(chunk[i++]);
	free(chunk[i]);
	free(chunk);
	return ;
}
