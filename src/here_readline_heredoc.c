/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_readline_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 11:26:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	signal_heredoc(void)
{
	signal(SIGINT, handler_heredoc);
	signal(SIGQUIT, handler_heredoc);
	return ;
}

int	readline_heredoc(int fd, int **cmd, t_flist **heredoc, int height)
{
	t_flist	*delimiter;
	char	*line;
	int		len;

	delimiter = find_delimiter(cmd, heredoc);
	len = 0;
	signal_heredoc();
	while (TRUE)
	{
		line = readline("> ");
		if (line == NULL)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(line, delimiter->name, ft_strlen(delimiter->name)) && \
ft_strlen(line) == ft_strlen(delimiter->name))
		{
			if (len == 0)
				write(fd, "\n", 1);
			free(line);
			break ;
		}
		putin_to_temp(line, &len, fd);
		free(line);
	}
	check_delimiter(cmd, delimiter, heredoc, height);
	return (FALSE);
}
