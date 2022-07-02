/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_child_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:59:17 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 04:44:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	child_heredoc(t_flist **heredoc, int height, \
char *installed)
{
	char	*directory;
	int		fd_temp;
	int		*cmdnum;

	clean_global();
	directory = ft_strjoin(installed, TEMP);
	cmdnum = malloc(sizeof(int) * 2);
	cmdnum[0] = 0;
	cmdnum[1] = 0;
	init_delimiter(&cmdnum, heredoc);
	while (TRUE)
	{
		fd_temp = make_temp(directory, cmdnum);
		if (readline_heredoc(fd_temp, &cmdnum, heredoc, height))
		{
			printf("%sheredoc Error\n", RED);
			g_global.last_exitcode = EXIT_FAILURE;
			exit(EXIT_FAILURE);
		}
		close(fd_temp);
		if (cmdnum[0] == height)
			exit (EXIT_SUCCESS);
	}
	exit (0);
}
