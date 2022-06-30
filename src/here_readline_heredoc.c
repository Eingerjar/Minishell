/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_readline_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 04:45:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	readline_heredoc(int fd, int **cmd, t_flist **heredoc, int height)
{
	t_flist	*delimiter;
	char	*line;
	int		len;

	delimiter = find_delimiter(cmd, heredoc);
	signal(SIGINT, handler_heredoc);
	signal(SIGQUIT, handler_heredoc);
	len = 0;
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
			break ;
		}
		putin_to_temp(line, &len, fd);
	}
	check_delimiter(cmd, delimiter, heredoc, height);
	return (FALSE);
}
