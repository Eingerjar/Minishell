/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_add_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:23:01 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 15:56:37 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_export(char *variable)
{
	char	**ret;
	int		length;
	int		i;

	i = 0;
	length = length_doublestring(g_global.wel_export) + 1;
	ret = malloc_wrap(sizeof(char *) * (length + 1));
	while (g_global.wel_export[i])
	{
		ret[i] = ft_strdup(g_global.wel_export[i]);
		if (ret[i] == NULL)
			print_error_exit("ft_add_export malloc error");
		i++;
	}
	ret[i++] = ft_strdup(variable);
	if (ret[i - 1] == NULL)
		print_error_exit("ft_add_export malloc error");
	ret[i] = NULL;
	free_doublestr(&g_global.wel_export, length - 1);
	g_global.wel_export = ret;
}
