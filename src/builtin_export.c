/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:24:03 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 20:32:05 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_env(char *env_str)
{
	while (*env_str != '\0')
	{
		if (*env_str == '=')
			return (1);
		env_str++;
	}
	return (0);
}

static int	is_var_dup(char **strvec, char *var)
{
	int	i;
	int	size;

	i = -1;
	size = count_equal_offset(var);
	while (strvec[++i])
	{
		if (ft_strncmp(strvec[i], var, size) == 0 \
				&& (strvec[i][size] == '\0' || strvec[i][size] == '='))
			return (1);
	}
	return (0);
}

static void	print_export(void)
{
	int	i;
	int	equal_offset;

	i = 0;
	while (g_global.wel_export[i])
	{
		write(1, "declare -x ", 11);
		equal_offset = count_equal_offset(g_global.wel_export[i]);
		write(1, g_global.wel_export[i], equal_offset + 1);
		if (g_global.wel_export[i][equal_offset] == '=')
		{
			write(1, "\"", 1);
			write(1, &g_global.wel_export[i][equal_offset + 1], \
					ft_strlen(&g_global.wel_export[i][equal_offset + 1]));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

void	builtin_export(char **argv)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
	{
		print_export();
		return ;
	}
	while (argv[++i])
	{
		if (is_var_dup(g_global.wel_export, argv[i]))
		{
			ft_update_strvec(g_global.wel_export, argv[i]);
			if (is_var_dup(g_global.wel_env, argv[i]))
				ft_update_strvec(g_global.wel_env, argv[i]);
			else
				ft_add_env(argv[i]);
		}
		else
		{
			ft_add_export(argv[i]);
			if (is_env(argv[i]))
				ft_add_env(argv[i]);
		}
	}
}
