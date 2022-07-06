/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:50:53 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 19:24:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_val_questionmark(void)
{
	char	*env_val;
	int		cnt;

	env_val = ft_itoa(g_global.last_exitcode);
	if (env_val == NULL)
		print_error_exit("ft_itoa malloc error\n");
	cnt = ft_strlen(env_val);
	free(env_val);
	return (cnt);
}

int	count_env_val(char *str, int i)
{
	int		cnt;
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		cnt = env_val_questionmark();
		return (cnt);
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
	free(env_val);
	return (cnt);
}
