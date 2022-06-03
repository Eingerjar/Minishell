/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/03 19:32:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int pre_error_check(char *line)
{
	char	**chunk;
	int		checknum;

	chunk = vertical_split(line);
	checknum= check_height(line);
	for(int i = 0; i < checknum; i++)
		printf("[%d]%s(%d)\n", i, chunk[i], (int)ft_strlen(chunk[i]));
	chunk_free(chunk, check_height(line));
	return (0);
}

/*
 * 에러인 경우 정리 
 * 1) dq가 안 닺힌 경우
 * 2) dp가 오히려 많은 경우(짝수 괜찮)
 * 3) sq가 안 닺힌 경우 
 * 4) 파이프 복수 발견 
 * 5) 파이프 내부에 커맨드 존재 안함(커맨드 존재 시 실행해보고 에러, 즉 내부에 뭐가 들었는지 처리 할 필요 없음)
 *
 * 에러 처리 과정
 * 기존 split 이 공간이 없을 경우 그냥 만들지 않고 넘어감. 따라서 문제가 생겼으므로, | 파이프 단위로 자를 때 || 이런 식으로 겹쳐 나와도 할당해주고 빈공간으로 넣어줘서
 * 에러 체크를 하는게 낳아 보인다. 
 * */
