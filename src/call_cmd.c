/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:58:34 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 22:19:28 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pipe(int *input_pipe, int *output_pipe)
{
	if (pipe(input_pipe) == -1 || pipe(output_pipe) == -1)
		print_error_exit("pipe error \n");
	dup2(input_pipe[0], 0);
	dup2(output_pipe[1], 1);
}

static void	close_other_pipe(int index, char **cmd, int **pipe)
{
	int	size;
	int	i;

	i = -1;
	size = count_char(cmd);
	while (++i < size)
	{
		if (i != index - 1 && i != index)
		{
			close(pipe[i][0]);
			close(pipe[i][1]);
		}
	}
	if (index != 0)
		close(pipe[index -1][1]);
}

void	call_cmd(int index, char **cmd, int **pipe)
{
	t_chunk	*chunk;
	int		input_pipe[2];
	int		output_pipe[2];
	pid_t	pid;

	chunk = init_structure(index, cmd);
	set_pipe(input_pipe, output_pipe);
	close_other_pipe(index, cmd, pipe);
	if (index != 0 && push_input(input_pipe, pipe, index, chunk->input))
		print_error_exit("push_input error\n");
	pid = fork();
	if (pid == 0)
		execute_process(chunk->argv);
	else if (pid > 0)
	{
		close(input_pipe[1]);
		close(output_pipe[1]);
		close(1);
		if (pull_output(output_pipe, pipe, index, chunk->output))
			print_error_exit("pull_output error\n");
		wait(&g_global.last_exitcode);
		exit(g_global.last_exitcode);
	}
	else
		print_error_exit("fork error\n");
}
