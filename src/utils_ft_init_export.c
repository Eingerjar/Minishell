/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_init_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:45:54 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 10:48:51 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_export(void)
{
	int		i;

	i = length_doublestring(environ);
	g_global.wel_export = malloc_wrap(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		g_global.wel_export[i] = ft_strdup(environ[i]);
		if (g_global.wel_export[i] == NULL)
			print_error_exit("init_export malloc error\n");
		i++;
	}
	g_global.wel_export[i] = NULL;
}
