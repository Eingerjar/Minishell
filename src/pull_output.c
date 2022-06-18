/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:17:44 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 22:18:01 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*get_fds(t_flist *f_output)
{
	int		i;
	int		*fds;

	i = 0;
	fds = (int *)malloc(sizeof(int) * count_flist(f_output));
	if (fds == NULL)
		return (NULL);
	while (f_output)
	{
		if (f_output->type == 0)
			fds[i++] = open(f_output->name, O_WRONLY | O_CREAT, 755);
		else
			fds[i++] = open(f_output->name, O_WRONLY | O_CREAT | O_APPEND, 755);
		f_output = f_output->next;
	}
	return (fds);
}

int	pull_output(int *output_pipe, int **pipe, int index, t_flist *f_output)
{
	int		i;
	int		*fds;
	char	buffer[1000];
	int		check;
	int		size;

	fds = get_fds(f_output);
	size = get_size_flist(f_output);
	check = read(output_pipe[0], buffer, 1000);
	while (check > 0)
	{
		write(pipe[index][1], buffer, check);
		if (f_output != NULL)
		{
			i = -1;
			while (++i < size)
				write(fds[i], buffer, check);
		}
		check = read(output_pipe[0], buffer, 1000);
	}
	if (check == -1)
		print_error_exit("output_pipe read error\n");
	return (0);
}
