/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:49:32 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 03:21:42 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_whitespace(char *line, int index, char redirect)
{
	int	opposite;
	int	i;

	opposite = what_is_opposite(redirect);
	i = skip_whitespace_r(index, line);
	if (line[i] == redirect || line[i] == opposite || \
!line[i] || line[i] == '|')
		return (line[i] * -1);
	if (is_whitespace(line[i - 1]))
		i--;
	return (i);
}
