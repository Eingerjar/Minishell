/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:52:27 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 16:06:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *str, int i)
{
	char	*env;
	int		index;

	index = skip_env(str, i) - i;
	env = (char *)malloc(sizeof(char) * index);
	if (env == NULL)
		return (NULL);
	ft_memcpy(env, str + i + 1, index - 1);
	env[index - 1] = '\0';
	return (env);
}
