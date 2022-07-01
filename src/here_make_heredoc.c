/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:06:52 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 04:06:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	make_heredoc(char *line, t_flist **target, int *heredocnum)
{
	int	i;
	int	max;

	i = -1;
	max = ft_strlen(line);
	while (line[++i])
	{
		if (line[i] == 60 || line[i] == 62)
			i = check_redirection_heredoc(line, i, target, heredocnum);
		else if (is_whitespace(line[i]))
			continue ;
		else if (line[i] == '|')
			continue ;
		else
			i = check_command(line, i);
		if (i >= max)
			break ;
	}
}
