/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:21:06 by cgim              #+#    #+#             */
/*   Updated: 2022/06/23 20:29:21 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_heredoc(int p_index, int h_num)
{
	char	*fname;
	char	*s_pindex;
	char	*s_hnum;
	int		size;
	int		fd;

	s_pindex = ft_itoa(p_index);
	s_hnum = ft_itoa(h_num);
	if (s_pindex == NULL || s_hnum == NULL)
		return (-1);
	size = ft_strlen(TEMP) + ft_strlen(s_pindex) + ft_strlen(s_hnum) + 2;
	fname = (char *)malloc(size);
	fname[0] = '\0';
	ft_strlcat(fname, TEMP, size);
	ft_strlcat(fname, s_pindex, size);
	ft_strlcat(fname, "-", size);
	ft_strlcat(fname, s_hnum, size);
	fd = open(fname, O_RDONLY);
	return (fd);
}

void	set_stdin(int **pipe, int index, t_flist *f_input)
{
	int	input_fd;
	int	h_num;

	if (f_input == NULL)
	{
		if (index == 0)
			return ;
		input_fd = pipe[index - 1][0];
	}
	else
	{
		if (index != 0)
			close(pipe[index - 1][0]);
		h_num = -1;
		while (f_input->next != NULL)
			f_input = f_input->next;
		if (f_input->type == 0)
			input_fd = open(f_input->name, O_RDONLY);
		else
			input_fd = open_heredoc(index, h_num);
		if (input_fd == -1)
			print_error_exit("fd open error");
	}
	dup2(input_fd, 0);
	close(input_fd);
}
