/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:36:36 by cgim              #+#    #+#             */
/*   Updated: 2022/06/23 20:51:50 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_write_mode(t_flist *f_output)
{
	int	output_fd;

	if (f_output->type == 0)
		output_fd = open(f_output->name, O_WRONLY | O_CREAT, 755);
	else
		output_fd = open(f_output->name, O_WRONLY | O_CREAT | O_APPEND, 755);
	return (output_fd);
}

void	set_stdout(int **pipe, int index, t_flist *f_output, char **cmd)
{
	int	output_fd;
	int	cmd_size;

	if (f_output == NULL)
	{
		cmd_size = count_cmd(cmd);
		if (index == cmd_size - 1)
			return ;
		output_fd = pipe[index][1];
	}
	else
	{
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
