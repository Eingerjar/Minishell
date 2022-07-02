/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_make_new_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:28:39 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:29:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**make_new_double(int omit, int length)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc_wrap(sizeof(char *) * length);
	while (i < length)
	{
		if (j == omit)
			j++;
		if (!g_global.wel_env[j])
			break ;
		ret[i] = ft_strdup(g_global.wel_env[j]);
		i++;
		j++;
	}
	ret[i] = NULL;
	return (ret);
}
