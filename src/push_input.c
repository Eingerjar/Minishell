/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:14:36 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 22:21:55 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_fd_to_fd(int r_fd, int w_fd)
{
	int		check;
	char	buffer[1000];

	check = read(r_fd, buffer, 1000);
	while (check > 0)
	{
		write(w_fd, buffer, check);
		check = read(r_fd, buffer, 1000);
	}
	if (check == -1)
		print_error_exit("write_fd_to_fd read error\n");
	close(r_fd);
}

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

int	push_input(int *input_pipe, int **pipe, int index, t_flist *f_input)
{
	int	fd;
	int	h_num;

	h_num = 0;
	while (f_input)
	{
		if (f_input->type == 0)
			fd = open(f_input->name, O_RDONLY);
		else
			fd = open_heredoc(index, h_num);
		if (fd == -1)
			return (1);
		if (f_input->next == NULL)
		{
			write_fd_to_fd(fd, input_pipe[1]);
			close(fd);
			return (0);
		}
		close(fd);
		f_input = f_input->next;
	}
	write_fd_to_fd(pipe[index - 1][0], input_pipe[1]);
	return (0);
}
