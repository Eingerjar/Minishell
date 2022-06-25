/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_other_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:44:36 by cgim              #+#    #+#             */
/*   Updated: 2022/06/25 17:52:46 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_first_cmd(int index, int **pipe, int pipe_size)
{
	int	i;

	i = -1;
	while (++i < pipe_size)
	{
		if (i != index)
			close(pipe[i][1]);
		close(pipe[i][0]);
	}
}

static void	close_last_cmd(int index, int **pipe, int pipe_size)
{
	int	i;

	i = -1;
	while (++i < pipe_size)
	{
		if (i != index - 1)
			close(pipe[i][0]);
		close(pipe[i][1]);
	}
}

static void	close_mid_cmd(int index, int **pipe, int pipe_size)
{
	int	i;

	i = -1;
	while (++i < pipe_size)
	{
		if (i == index - 1)
			close(pipe[i][1]);
		else if (i == index)
			close(pipe[i][0]);
		else
		{
			close(pipe[i][0]);
			close(pipe[i][1]);
		}
	}
}

void	close_other_pipe(int index, char **cmd, int **pipe)
{
	int	pipe_size;

	pipe_size = count_cmd(cmd) - 1;
	if (pipe_size == 0)
		return ;
	if (index == 0)
		close_first_cmd(index, pipe, pipe_size);
	else if (index == pipe_size)
		close_last_cmd(index, pipe, pipe_size);
	else
		close_mid_cmd(index, pipe, pipe_size);
}
