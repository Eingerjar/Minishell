/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_del_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:30:00 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:31:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_del_env(char *variable)
{
	char	**ret;
	int		length;
	int		where_var;
	int		i;

	i = 0;
	where_var = -1;
	length = length_doublestring(g_global.wel_env);
	while (i < length)
	{
		if (find_in_env(g_global.wel_env[i], variable))
		{
			where_var = i;
			break ;
		}
		i++;
	}
	if (where_var != -1)
	{
		ret = make_new_double(where_var, length);
		free_doublestr(&g_global.wel_env, length);
		g_global.wel_env = ret;
	}
}
