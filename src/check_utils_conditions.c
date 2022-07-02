/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_conditions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:16:47 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 04:23:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	utils_conditions(char c, int *index)
{
	if (is_whitespace(c))
		return (TRUE);
	if (c == '<' || c == '>' || c == '|')
	{
		(*index)--;
		return (TRUE);
	}
	if (c == 59 || c == 44 || c == 92)
	{
		(*index) = c * -1;
		return (TRUE);
	}
	return (FALSE);
}
