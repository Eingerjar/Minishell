/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:24:03 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 15:01:34 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_env(char *env_str)
{
	if (ft_isalpha(env_str[0]) == 0 && env_str[0] != '_')
		return (0);
	env_str++;
	while (*env_str != '\0')
	{
		if (*env_str == '=')
			return (1);
		if (ft_isalnum(env_str[0]) != 0 || env_str[0] != '_')
			env_str++;
		else
			return (0);
	}
	return (1);
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

static void	add_export(char *arg)
{
	int	equal_offset;

	equal_offset = count_equal_offset(arg);
	if (is_var_dup(g_global.wel_export, arg))
	{
		ft_update_strvec(g_global.wel_export, arg);
		if (is_var_dup(g_global.wel_env, arg))
			ft_update_strvec(g_global.wel_env, arg);
		else
			ft_add_env(arg);
	}
	else
	{
		ft_add_export(arg);
		if (arg[equal_offset] == '=')
			ft_add_env(arg);
	}
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
		if (is_env(argv[i]))
			add_export(argv[i]);
		else
		{
			ft_putstr_fd("export: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
		}
	}
}
