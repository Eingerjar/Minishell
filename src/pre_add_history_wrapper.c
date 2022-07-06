/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_add_history_wrapper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:34:34 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 02:54:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_history_wrapper(char **line)
{
	if (ft_strlen((*line)) == 0)
	{
		g_global.last_exitcode = 0;
		return ;
	}
	else
		add_history((*line));
	return ;
}
