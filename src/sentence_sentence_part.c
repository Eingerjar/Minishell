/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_sentence_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:57:25 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 12:45:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	sentence_part(char *line)
{
	char	**chunks;
	int		chunk_height;
	int		**pipe;

	chunks = vertical_split(line);
	chunk_height = check_height(line);
	pipe = init_pipe(chunk_height - 1);
	fork_cmds(chunk_height, chunks, pipe);
	chunk_free(chunks, (size_t)chunk_height);
	return (FALSE);
}
