/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_sentence_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:57:25 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 04:55:23 by haryu            ###   ########.fr       */
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

/*
	수정 필요 
	예를 들어 커맨드 1개일 때 -> 파이프 만들 필요 없음 
	빌트인 함수 일 때 -> 파이프 만들 필요 없음 + call cmd를 할 때 따로 fork 할 필요 없음(바로 호출? 혹은 내 쪽에서 직접 호출?)
*/
