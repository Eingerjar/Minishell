/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:50:53 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 21:30:13 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_val(char *str, int i)
{
	int		cnt;
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		env = ft_itoa(g_global.last_exitcode);
		if (env == NULL)
			print_error_exit("ft_itoa malloc error\n");
		return (ft_strlen(env));
	}
	if (ft_isdigit(str[i + 1]))
		return (0);
	env = get_env(str, i);
	if (env == NULL)
		print_error_exit("get_env error\n");
	env_val = ft_get_env(env);
	if (env_val == NULL)
		cnt = 0;
	else
		cnt = ft_strlen(env_val);
	free(env);
	return (cnt);
}
