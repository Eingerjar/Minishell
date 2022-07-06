/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vertical_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:20:47 by haryu             #+#    #+#             */
/*   Updated: 2022/07/06 13:30:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strndup(char *line, size_t byte)
{
	char	*ret;
	size_t	i;

	ret = malloc_wrap(sizeof(char) * (byte + 1));
	i = 0;
	while (i < byte)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static int	make_vertical(char **chunks, char *line, int *index, int *previous)
{
	int	len;

	len = ft_strlen(line);
	if (!line[*index])
		*index += 1;
	(*chunks) = ft_strndup(line + *previous, *index - *previous);
	if (*index > len)
		return (len);
	else
	{
		*index += 1;
		while (is_whitespace(line[*index]))
			(*index)++;
		*previous = (*index);
	}
	return (*index);
}

static int	skip_white_space(char *line, int index)
{
	while (is_whitespace(line[index]))
		index++;
	return (index);
}

static void	cut_vertical(char ***chunks, char *line, size_t height)
{
	int		i;
	size_t	deep;
	int		previous;

	i = 0;
	deep = 0;
	previous = 0;
	while (deep < height && line[i])
	{
		if (is_whitespace(line[i]))
			i = skip_white_space(line, i);
		if (line[i] == 34 || line[i] == 39)
			i = skip_quotes(line, i, line[i]);
		if (!line[i] || line[i] == '|')
			make_vertical(&(*chunks)[deep++], line, &i, &previous);
		else if (!line[i + 1])
		{
			i++;
			make_vertical(&(*chunks)[deep++], line, &i, &previous);
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
	ret = (char **)malloc_wrap(sizeof(char *) * (height + 1));
	ret[height] = NULL;
	cut_vertical(&ret, line, height);
	return (ret);
}
