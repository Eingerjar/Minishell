/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_is_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 05:24:42 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 06:13:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(t_chunk *chunk)
{
	int	i;

	i = 0;
	while (BUILTIN[i])
	{
		if (BUILTIN[i] == chunk->argv[0][0])
		{
			if (!ft_strncmp(&BUILTIN[i], chunk->argv[0], \
ft_strlen(chunk->argv[0])))
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
