/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:50:53 by cgim              #+#    #+#             */
/*   Updated: 2022/06/11 13:31:10 by cgim             ###   ########.fr       */
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
		env = ft_itoa(global.last_exitcode);
		if (env == NULL)
			print_error_exit("ft_itoa malloc error\n");
		return (ft_strlen(env));
	}
	if (ft_isdigit(str[i + 1]))
		return (0);
	env = get_env(str, i);
	if (env == NULL)
		print_error_exit("get_env error\n");
	env_val = getenv(env);
	if (env_val == NULL)
		cnt = 0;
	else
		cnt = ft_strlen(env_val);
	free(env);
	return (cnt);
}
