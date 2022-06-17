/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:57:25 by haryu             #+#    #+#             */
/*   Updated: 2022/06/17 22:29:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global g_global;

void	prepare_pipe(int ***pipes, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (pipe((*pipes)[i]) == -1)
		{
			printf("Pipe error : %s\n", strerror(errno));
			g_global.last_exitcode = 1;
		}
		i++;
	}
	if (g_global.last_exitcode == 1)
		exit (1);
	return ;
}

int **init_pipe(int cmdnum)
{
	int		**pipes;
	int		i;

	pipes = malloc_wrap(sizeof(int *) * cmdnum);
	i = -1;
	while (++i < cmdnum)
		pipes[i] = malloc_wrap(sizeof(int) * 2);
	prepare_pipe(&pipes, cmdnum);
	if (g_global.last_exitcode == 1)
		exit(1);
	return (pipes);
}

void	close_pipe(int **pipe, int height)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < height)
	{
		while (++j < 2)
		{
			if (i == height - 1 && j == 0)
				continue ;
			else
				close(pipe[i][j]);
			j++;
		}
		j = -1;
	}
}

int	final_print(int **pipe, int height)
{
	int		cnt;
	char	buff[3];

	cnt = read(pipe[height - 1][0], buff, 1);
	if (cnt != 0)
		write(1, buff, 1);
	while (cnt)
	{
		cnt = read(pipe[height - 1][0], buff, 1);
		write(1, buff, 1);
		if (cnt < 0)
			break ;
	}
	return (FALSE);
}

pid_t	*init_pids(int numbers)
{
	pid_t	*pids;

	pids = malloc_wrap(sizeof(pid_t) * numbers);
	return (pids);
}

int	kill_them_all(pid_t *childs, int numbers)
{
	int index;

	index = -1;
	while (++index < numbers)
		kill(childs[index], SIGKILL);
	return (FALSE);
}

int	ft_wait(pid_t *childs, int numbers)
{
	int		index;
	int		stats;
	int		kill_flag;
	pid_t	temp;

	index = -1;
	kill_flag = 0;
	while (++index < numbers)
	{
		temp = wait(&stats);
		if (WEXITSTATUS(stats) != 0 && kill_flag == 0)
		{
			kill_them_all(childs, numbers);
			kill_flag++;
			(void)temp;
		}
	}
	g_global.last_exitcode = WEXITSTATUS(stats);
	if (kill_flag != 0)
		return (TRUE);
	return (FALSE);
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
		if (childs[index] != 0)
			continue ;
		else if (childs[index] == 0)
		{
			sleep(3);
			write(pipes[height - 1][1], "child process test!\n", ft_strlen("child process test!\n"));
			print_chunks(chunks, height);
			//call_cmd(int, height, chunks, pipes)
			//if (index == 3)
			//	exit(1);
			exit(0);
		}
	}
	close_pipe(pipes, height);
	if (ft_wait(childs, height))
		return (TRUE);
	return (FALSE);
}

int	sentence_part(char *line)
{
	char	**chunks;
	int		chunk_height;
	int		**pipe;

	chunks = vertical_split(line);
	chunk_height = check_height(line);
	pipe = init_pipe(chunk_height);
	if (!fork_cmds(chunk_height, chunks, pipe))
		final_print(pipe, chunk_height);
	close(pipe[chunk_height - 1][0]);
	chunk_free(chunks, (size_t)chunk_height);
	return (FALSE);
}
