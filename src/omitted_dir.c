/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omitted_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:46:32 by haryu             #+#    #+#             */
/*   Updated: 2022/06/17 21:59:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

char	*omit_longstr(char	*str)
{
	char	*ret;
	int		index;

	ret = malloc_wrap(sizeof(char) * 11);
	index = -1;
	while (++index < 10)
	{
		if (index < 7)
			ret[index] = str[index];
		else
			ret[index] = '.';
	}
	ret[index] = '\0';
	return (ret);
}

char	*make_current_dir(char ***omitted)
{
	char	*ret;
	char	*temp;
	char	*temp2;
	int		index;

	index = -1;
	ret = ".../";
	while (++index < 3)
	{
		if (ft_strlen((*omitted)[index]) > 10)
			temp = omit_longstr((*omitted)[index]);
		else
			temp = (*omitted)[index];
		temp2 = ft_strjoin(temp, "/");
		free(temp);
		ret = ft_strjoin(ret, temp2);
		free(temp2);
	}
	return (ret);
}

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
