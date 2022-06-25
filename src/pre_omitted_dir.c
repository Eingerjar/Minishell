/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_omitted_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:46:32 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 08:08:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	splitlen(char **root)
{
	int	i;

	i = 0;
	while (root[i])
		i++;
	return (i);
}

char	*omitted_dir(char *dir)
{
	char	**splitted;
	char	**omitted;
	char	*ret;
	int		index;
	int		max;

	splitted = ft_split(dir + 1, '/');
	omitted = malloc_wrap(sizeof(char *) * 4);
	omitted[3] = 0;
	index = -1;
	max = splitlen(splitted);
	while (++index < max)
	{
		if (max > 2 && !splitted[index + 1])
		{
			omitted[0] = splitted[index - 2];
			omitted[1] = splitted[index - 1];
			omitted[2] = splitted[index];
			break ;
		}
	}
	if (index > 2)
		ret = make_current_dir(&omitted);
	else if (index > 1)
		ret = ft_strjoin(ft_getcwd(), "/");
	else
		ret = ft_getcwd();
	free(omitted);
	return (ret);
}
