/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:36:36 by cgim              #+#    #+#             */
/*   Updated: 2022/06/25 12:33:25 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_write_mode(t_flist *f_output)
{
	int	output_fd;

	if (f_output->type == 0)
		output_fd = open(f_output->name, O_WRONLY | O_CREAT, 0644);
	else
		output_fd = open(f_output->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (output_fd);
}

void	set_stdout(int **pipe, int index, t_flist *f_output, char **cmd)
{
	int	output_fd;
	int	cmd_size;

	cmd_size = count_cmd(cmd);
	if (f_output == NULL)
	{
		if (index == cmd_size - 1)
			return ;
		output_fd = pipe[index][1];
	}
	else
	{
		if (index != cmd_size - 1)
			close(pipe[index][1]);
		while (f_output->next != NULL)
		{
			output_fd = open_write_mode(f_output);
			close(output_fd);
			f_output = f_output->next;
		}
		output_fd = open_write_mode(f_output);
	}
	dup2(output_fd, 1);
	close(output_fd);
}
