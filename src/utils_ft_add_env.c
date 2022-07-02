/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_add_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:27:01 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:27:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_env(char *variable)
{
	char	**ret;
	int		length;
	int		i;

	i = 0;
	length = length_doublestring(g_global.wel_env) + 1;
	ret = malloc_wrap(sizeof(char *) * (length + 1));
	while (g_global.wel_env[i])
	{
		ret[i] = ft_strdup(g_global.wel_env[i]);
		i++;
	}
	ret[i++] = ft_strdup(variable);
	ret[i] = NULL;
	free_doublestr(&g_global.wel_env, length - 1);
	g_global.wel_env = ret;
}
