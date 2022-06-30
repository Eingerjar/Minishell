/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:29:31 by cgim              #+#    #+#             */
/*   Updated: 2022/06/30 17:04:15 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_env_val(char *dst, char *str, int i, int cnt)
{
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		env_val = ft_itoa(g_global.last_exitcode);
		if (env_val == NULL)
			print_error_exit("ft_itoa malloc error\n");
		ft_memcpy(dst + cnt, env_val, ft_strlen(env_val));
		free(env_val);
		return ;
	}
	if (ft_isdigit(str[i + 1]))
		return ;
	env = get_env(str, i);
	if (env == NULL)
		print_error_exit("get_env error\n");
	env_val = ft_get_env(env);
	free(env);
	if (env_val == NULL)
		return ;
	else
		ft_memcpy(dst + cnt, env_val, ft_strlen(env_val));
	free(env_val);
}
