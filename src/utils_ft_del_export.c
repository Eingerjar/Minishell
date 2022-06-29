/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_del_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:09:32 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 14:56:05 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_export(char *variable)
{
	char	**ret;
	int		length;
	int		where_var;
	int		i;

	i = 0;
	where_var = -1;
	length = length_doublestring(g_global.wel_export);
	while (i < length)
	{
		if (find_in_env(g_global.wel_export[i], variable))
		{
			where_var = i;
			break ;
		}
		i++;
	}
	if (where_var != -1)
	{
		ret = make_new_double(where_var, length);
		free_doublestr(&g_global.wel_export, length);
		g_global.wel_export = ret;
	}
}
