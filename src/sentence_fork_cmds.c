/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_fork_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:46:05 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 06:24:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fake_process(void)
{
	usleep(300);
	exit(0);
}

void	builtin_process(pid_t **child, char	**chunks, \
t_chunk *chunk, int **pipes)
{
	(*child)[0] = fork();
	if ((*child)[0] == 0)
		fake_process();
	else
		call_cmd(0, chunks, chunk, pipes);
}

int	fork_cmds(int height, char **chunks, int **pipes)
{
	pid_t		*childs;
	t_chunk		*chunk;
	int			index;

	childs = init_pids(height);
	index = -1;
	while (++index < height)
	{
		chunk = init_structure(index, chunks);
		if (height == 1 && is_builtin(chunk) && index == 0)
			builtin_process(&childs, chunks, chunk, pipes);
		else
			childs[index] = fork();
		if (childs[index] != 0)
			free_t_chunk(chunk);
		else if (childs[index] == 0)
			call_cmd(index, chunks, chunk, pipes);
	}
	close_pipe(pipes, height - 1);
	if (ft_wait(childs, height))
		return (TRUE);
	return (FALSE);
}
/*
해당 파트에서 인자 1개일 때 callcmd 직접 실행하도록 수정해야 함
커맨드 1개일 때 
1. 빌트인인가?
	call_cmd를 그냥 실행 
	빌트인 여부 판단
	빌트인 스위칭으로 실행
	중요사항 ) 빌트인의 경우 exit을 하면 안 되며, exitcode 만 저장해야함
2. 빌트인이 아닌가?
	기존 로직과 동일 
*/