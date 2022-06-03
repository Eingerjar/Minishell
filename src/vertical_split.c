/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:20:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/03 19:51:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char *ft_strndup(char *line, size_t byte)
{
	char	*ret;
	size_t	i;

	ret = malloc(sizeof(char) * (byte + 1));
	if (!ret)
	{
		printf("Please check yuour Error\n");
		exit(0);
	}
	i = 0;
	while(i < byte)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t check_height(char *line)
{
	size_t ret;
	int	sq;
	int	dq;
	int	i;

	i = -1;
	ret = 1;
	sq = 0;
	dq = 0;
	while(line[++i])
	{
		if (line[i] == '\'' && sq == 0)
			sq++;
		else if (line[i] == '\'' && sq == 1)
			sq--;
		if (line[i] == '"' && dq == 0)
			dq++;
		else if (line[i] == '"' && dq == 1)
			dq--;
		if (line[i] == '|' && dq == 0 && sq == 0)
			ret++;
	}
	return (ret);
}

static void cut_vertical(char ***chunks, char *line, size_t height)
{
	int 	i;
	size_t	deep;
	int 	sq;
	int		dq;
	int		previous;

	i = 0;
	sq = 0;
	dq = 0;
	deep = 0;
	previous = 0;
	while(deep < height)
	{
		if(line[i] == '\'' && sq == 0)
			sq++;
		else if (line[i] == '\'' && sq == 1)
			sq--;
		if (line[i] == '"' && dq == 0)
			dq++;
		else if (line[i] == '"' && dq == 1)
			dq--;
		if ((line[i] == '|' || !line[i]) && dq == 0 && sq == 0)
		{
			(*chunks)[deep] = ft_strndup(line + previous, i - previous);
			previous = i + 1;
			deep++;
		}
		i++;
	}
}


char	**vertical_split(char *line)
{
	char	**ret;
	size_t	height;

	ret = NULL;
	height = check_height(line);
	ret = (char **)malloc(sizeof(char *) * (height + 1));
	if (!ret)
	{
		printf("Please check Error\n");
		exit(1);
	}
	ret[height] = NULL;
	cut_vertical(&ret, line, height);
	printf("vertical bar : %d\n", (int)height);
	return (ret);
}
