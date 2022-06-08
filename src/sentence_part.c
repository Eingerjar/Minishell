/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:25:31 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 17:16:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int final_print(int **pipe, int pipenum);

void call_cmd(int index, char **chunk, int **pipe, char *installed);

int	pipe_malloc(int ***ex_pipe, int pipenum);

int	kill_process(pid_t *cmds, int index, int pipenum);

int	init_malloc(pid_t **cmds, int **status);

int sentence_part(char **chunk, int pipenum, char *installed)
{
	pid_t	*cmds;
	int		**ex_pipe;
	int		i;
	int		*status;

	/*
	 * 시그널 처리
	 */
	if(pipe_malloc(&ex_pipe, pipenum))
	{
		printf("Error!\n");
		exit(1);
	}
	cmds = malloc(sizeof(pid_t) * pipenum);
	if (!cmds)
	{
		printf("Error!\n");
		exit(1);
	}
	status = malloc(sizeof(int) * pipenum);
	if (!status)
	{
		printf("Error!\n");
		exit(1);
	}
	i = 0;
	while(i < pipenum)
	{
		cmds[i] = fork();
		if (cmds[i] == 0)
		{
			call_cmd(i, chunk, ex_pipe, installed);
			exit(0);
		}
		i++;
	}
	i = 0;
	while(i < pipenum)
	{
		waitpid(cmds[i], &status[i], 0);
		if (!WIFEXITED(status[i]))
			kill_process(cmds, i, pipenum);
		i++;
	}
	if (final_print(ex_pipe, pipenum))
		exit(1);
	exit(0);
}
