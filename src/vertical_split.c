/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:20:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/11 00:36:53 by haryu            ###   ########.fr       */
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
	while (i < byte)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void cut_vertical(char ***chunks, char *line, size_t height)
{
	int 	i;
	size_t	deep;
	int		previous;

	i = 0;
	deep = 0;
	previous = 0;
	while (deep < height && line[i])
	{
		if (i == 0 && line[0] == ' ')
		{
			while (line[i] == ' ')
				i++;
			previous = i - 1;
		}
		if (line[i] == 34 || line[i] == 39)
			i = skip_quotes(line, i, line[i]);
		if (line[i] == '|' || !line[i + 1])
		{
			if (!line[i + 1])
				i++;
			(*chunks)[deep] = ft_strndup(line + previous, i - previous);
			if (!line[i])
				break ;
			else if (line[i + 1] == ' ')
			{
				i += 1;
				while (line[i] == ' ')
					i++;
				previous = --i;
			}
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
