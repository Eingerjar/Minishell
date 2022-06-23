/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_omitted_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:46:32 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:32:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*omitted_dir(char *dir)
{
	char	**splitted;
	char	**omitted;
	char	*ret;
	int		index;

	splitted = ft_split(dir, '/');
	omitted = malloc_wrap(sizeof(char *) * 3);
	index = -1;
	while (splitted[++index])
	{
		if (!splitted[index + 1])
		{
			omitted[0] = splitted[index - 2];
			omitted[1] = splitted[index - 1];
			omitted[2] = splitted[index];
			break ;
		}
	}
	ret = make_current_dir(&omitted);
	free(omitted);
	return (ret);
}
