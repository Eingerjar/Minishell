/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_skip_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:46:17 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 03:02:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_whitespace_r(int i, char *line)
{
	while (is_whitespace(line[i]))
	{
		if (i >= (int)ft_strlen(line))
			return (PARSE);
		i++;
	}
	return (i);
}
