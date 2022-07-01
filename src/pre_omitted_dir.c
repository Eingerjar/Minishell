/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_omitted_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:46:32 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 20:21:04 by haryu            ###   ########.fr       */
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

static void	setting_directiory(int *index, char **omitted, char **splitted)
{
	int	max;

	max = splitlen(splitted);
	while (++(*index) < max)
	{
		if (max > 2 && !splitted[(*index) + 1])
		{
			omitted[0] = splitted[(*index) - 2];
			omitted[1] = splitted[(*index) - 1];
			omitted[2] = splitted[(*index)];
			break ;
		}
	}
}

static void	split_free(char **splitted)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted[i]);
	free(splitted);
}

char	*omitted_dir(char *dir)
{
	char	**splitted;
	char	**omitted;
	char	*ret;
	int		index;

	splitted = ft_split(dir + 1, '/');
	omitted = malloc_wrap(sizeof(char *) * 4);
	omitted[3] = 0;
	index = -1;
	setting_directiory(&index, omitted, splitted);
	if (index > 2)
		ret = make_current_dir(&omitted);
	else if (index > 1)
		ret = ft_strjoin(ft_getcwd(), "/");
	else
		ret = ft_getcwd();
	free(omitted);
	split_free(splitted);
	return (ret);
}
