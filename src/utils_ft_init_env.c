/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ft_init_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:17:50 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 10:44:22 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_env(void)
{
	int		i;

	i = length_doublestring(environ);
	g_global.wel_env = malloc_wrap(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		g_global.wel_env[i] = ft_strdup(environ[i]);
		i++;
	}
	g_global.wel_env[i] = NULL;
}
