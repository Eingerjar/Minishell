/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_readline_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 03:54:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	heredoc_tcsetattr(struct termios *new)
{
	(*new) = g_global.old_settings;
	new->c_lflag |= ICANON;
	new->c_cc[VQUIT] = 255;
	tcsetattr(0, TCSANOW, new);
	return ;
}

static void	signal_heredoc(struct termios *new)
{
	signal(SIGINT, handler_heredoc);
	heredoc_tcsetattr(new);
	return ;
}

static void	check_len(char **line, int fd, int len)
{
	if (len == 0)
		write(fd, "\n", 1);
	free(*line);
	return ;
}

int	readline_heredoc(int fd, int **cmd, t_flist **heredoc, int height)
{
	t_flist			*delimiter;
	struct termios	new;
	char			*line;
	int				len;

	delimiter = find_delimiter(cmd, heredoc);
	len = 0;
	signal_heredoc(&new);
	while (TRUE)
	{
		line = readline("> ");
		if (line == NULL)
			exit(0);
		if (!ft_strncmp(line, delimiter->name, ft_strlen(delimiter->name)) && \
ft_strlen(line) == ft_strlen(delimiter->name))
		{
			check_len(&line, fd, len);
			break ;
		}
		putin_to_temp(line, &len, fd);
		free(line);
	}
	check_delimiter(cmd, delimiter, heredoc, height);
	return (FALSE);
}
