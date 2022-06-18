/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_omit_longstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:12:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:12:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

char	*omit_longstr(char	*str)
{
	char	*ret;
	int		index;

	ret = malloc_wrap(sizeof(char) * 11);
	index = -1;
	while (++index < 10)
	{
		if (index < 7)
			ret[index] = str[index];
		else
			ret[index] = '.';
	}
	ret[index] = '\0';
	return (ret);
}
