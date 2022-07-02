/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_get_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:31:43 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:32:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_get_env(char *variable)
{
	char	*ret;
	int		i;
	int		length;
	int		where;

	i = -1;
	where = -1;
	length = length_doublestring(g_global.wel_env);
	while (++i < length)
	{
		if (find_in_env(g_global.wel_env[i], variable))
		{
			where = i;
			break ;
		}
	}
	if (where == -1)
		return (NULL);
	ret = ft_strdup(g_global.wel_env[i] + ft_strlen(variable) + 1);
	return (ret);
}
