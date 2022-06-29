/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_del_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:09:32 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 21:01:11 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_new_double_export(int omit, int length)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc_wrap(sizeof(char *) * length);
	while (i < length)
	{
		if (j == omit)
			j++;
		if (!g_global.wel_export[j])
			break ;
		ret[i] = ft_strdup(g_global.wel_export[j]);
		i++;
		j++;
	}
	ret[i] = NULL;
	return (ret);
}

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
		ret = make_new_double_export(where_var, length);
		free_doublestr(&g_global.wel_export, length);
		g_global.wel_export = ret;
	}
}
