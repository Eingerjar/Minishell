/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:41:40 by haryu             #+#    #+#             */
/*   Updated: 2022/06/10 21:01:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	check_height(char *line)
{
	size_t	ret;
	int		sq;
	int		dq;
	int		i;

	i = -1;
	ret = 1;
	sq = 0;
	dq = 0;
	while (line[++i])
	{
		if (line[i] == '\'' && sq == 0)
			sq++;
		else if (line[i] == '\'' && sq == 1)
			sq--;
		if (line[i] == '"' && dq == 0)
			dq++;
		else if (line[i] == '"' && dq == 1)
			dq--;
		if (line[i] == '|' && dq == 0 && sq == 0)
			ret++;
	}
	return (ret);
}
