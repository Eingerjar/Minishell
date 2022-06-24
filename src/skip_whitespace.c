/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:27:34 by cgim              #+#    #+#             */
/*   Updated: 2022/06/24 10:01:49 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_whitespace(char chr)
{
	if (chr == '\t' || chr == '\n' || chr == '\v'
		|| chr == '\f' || chr == '\r' || chr == ' ')
		return (1);
	return (0);
}

int	skip_whitespace(char *cmd, int i)
{
	while (is_whitespace(cmd[i]))
		i++;
	return (i);
}
