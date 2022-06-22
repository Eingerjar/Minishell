/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find_in_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:27:51 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:28:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_in_env(char *target, char *str)
{
	int		i;
	int		ret;
	char	**split_target;

	i = 0;
	ret = 0;
	split_target = ft_split(target, '=');
	ret = ft_strncmp(split_target[0], str, ft_strlen(str));
	free_doublestr(&split_target, 2);
	if (ret == 0)
		return (TRUE);
	return (FALSE);
}
