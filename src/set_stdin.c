/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:21:06 by cgim              #+#    #+#             */
/*   Updated: 2022/06/26 15:46:42 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_heredoc(int cmd_index, int h_num)
{
	char	*fname;
	char	*s_cindex;
	char	*s_hnum;
	int		size;
	int		fd;

	s_cindex = ft_itoa(cmd_index);
	s_hnum = ft_itoa(h_num);
	if (s_cindex == NULL || s_hnum == NULL)
		return (-1);
	size = ft_strlen(g_global.heredir) + ft_strlen(TEMPFILE) +\
	ft_strlen(s_cindex) + ft_strlen(s_hnum) + 2;
	fname = (char *)malloc(size);
	fname[0] = '\0';
	ft_strlcat(fname, g_global.heredir, size);
	ft_strlcat(fname, TEMPFILE, size);
	ft_strlcat(fname, s_cindex, size);
	ft_strlcat(fname, "_", size);
	ft_strlcat(fname, s_hnum, size);
	fd = open(fname, O_RDONLY);
	return (fd);
}

static int	last_f_input(int index, t_flist *f_input)
{
	int	input_fd;
	int	heredoc_cnt;

	heredoc_cnt = -1;
	while (f_input->next != NULL)
	{
		if (f_input->type == 1)
			heredoc_cnt++;
		f_input = f_input->next;
	}
	if (f_input->type == 0)
		input_fd = open(f_input->name, O_RDONLY);
	else
		input_fd = open_heredoc(index, ++heredoc_cnt);
	if (input_fd == -1)
		print_error_exit("fd open error");
	return (input_fd);
}

void	set_stdin(int **pipe, int index, t_flist *f_input)
{
	int	input_fd;

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
		input_fd = last_f_input(index, f_input);
	}
	dup2(input_fd, 0);
	close(input_fd);
}
