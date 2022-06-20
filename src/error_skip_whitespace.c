/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_skip_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:46:17 by haryu             #+#    #+#             */
/*   Updated: 2022/06/20 02:28:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_whitespace(int i, char *line)
{
	while (line[i] == 32)
	{
		if (i >= (int)ft_strlen(line))
			return (PARSE);
		else if (line[i] != 32)
			break ;
		i++;
	}
	return (i);
}
