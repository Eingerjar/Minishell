/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sentence_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:57:25 by haryu             #+#    #+#             */
/*   Updated: 2022/06/15 23:27:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global global;

void	prepare_pipe(int ***pipes, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Pipe error : %s\n", strerror(errno));
			global.last_exitcode = 1;
		}
		i++;
	}
	if (global.last_exitcode == 1)
		exit (1);
	return ;
}

int **init_pipe(int cmdnum)
{
	int		**pipes;
	int		i;

	pipes = (int **)mallo(sizeof(int *) * cmdnum);
	if (!pipes)
	{
		printf("malloc error\n");
		global.last_exitcode = 1;
	}
	i = -1;
	while (++i < cmdnum)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			printf("malloc error\n");
			global.last_exitcode = 1;
		}
	}
	prepare_pipe(&pipes, cmdnum);
	if (global.last_exitcode == 1)
		exit(1);
	return (pipes);
}

void	close_pipe(int **pipe, int height)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < height)
	{
		while (j < 2)
		{
			if (i == height - 1 && j == 1)
				return ;
			close(pipe[i][j]);
			j++;
		}
		j = 0;
	}
}

int	final_print(int **pipe, int height)
{
	return (FALSE);
}

pid_t	*init_pids(int numbers)
{
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * numbers);
	if (!pids)
	{
		printf("malloc error\n");
		global.last_exitcode = 1;
		exit (1);
	}
	return (pids);
}

void	ft_wait(pid_t *childs, int numbers)
{
	int		index;
	int		stats;
	pid_t	temp;

	index = -1;
	while(++index < numbers)
	{
		temp = wait(&stats);
		// 종료 신호받기 구현하면 됨! 
	}
	return ;
}

int	fork_cmds(int height, char **chunks, int **pipes)
{
	pid_t	*childs;
	int		index;

	childs = init_pids(height);
	index = -1;
	while (++index < height)
	{
		childs[index] = fork();
		if (childs[index] == 0)
		{
			print_chunks(chunks, height);
			//call_cmd(int, height, chunks, pipes)
			exit(0);
		}
	}
	close_pipe(pipe, height);
	ft_wait(childs, height);
	return (FALSE);
}

int	pre_seneten_part(char *line)
{
	char	**chunks;
	int		chunk_height;
	int		**pipe;
	int		index;

	chunks = vertical_split(line);
	chunk_height = check_height(line);
	index = 0;
	pipe = init_pipe(chunk_height);
	if(fork_cmds(chunk_height, chunks, pipe))
		return ;
	// 1. 파이프 할당 
	// 2. fork
			// 3. 파이프 닫기
		// 4. wait
			// exit 코드 감시 
			// 시그널 보내기 방식 활용 에러시 킬 전체; 
	// 5. 출력 
	// 프리
		// 파이프 할당 사항 전체 프리 
		// 청크 프리
	// 7. 엑신 코드 지정
	return ;
}