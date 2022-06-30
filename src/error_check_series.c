/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_series.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:23:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/30 13:24:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	what_is_opposite(char redirect)
{
	if (redirect == 60)
		return (62);
	else
		return (60);
}

int	check_redirection(char *line, int index, char redirect)
{
	int	opposite;

	opposite = what_is_opposite(redirect);
	if (is_whitespace(line[index + 1]))
		index = check_whitespace(line, index + 1, redirect);
	else if (line[index + 1] == '\n' || index + 1 == (int)ft_strlen(line))
		return (PARSE);
	else if (line[index + 1] == redirect)
	{
		if (line[index + 2] == redirect || line[index + 2] == opposite)
			return (line[index + 2] * -1);
		return (check_redirection(line, index + 1, line[index + 1]));
	}
	else if (line[index + 1] == opposite)
		return (line[index + 1] * -1);
	else if (line[index + 1] == '|')
		return ('|' * -1);
	else if (line[index + 1] == '&')
		return (-38);
	return (index);
}

int	check_pipe(char *line, int index)
{
	if (is_whitespace(line[index + 1]))
	{
		index += 1;
		if (is_whitespace(line[index + 1]))
			while (is_whitespace(line[index]) && line[index])
					index++;
		if (line[index] == '|' || line[index] == '\0')
			return ('|' * -1);
		return (index);
	}
	else if (line[index + 1] == '|')
	{
		if (line[index + 2] == '|')
			return ('|' * -1);
		else
			return (-38);
	}
	else if (line[index + 1] == '<' || line[index + 1] == '>')
		return (line[index + 1] * -1);
	else if (!line[index + 1])
		return ('|' * -1);
	else
		return (index);
}

int	skip_quotes(char *line, int index, char quotes)
{
	int	i;
	int	flag;

	i = index + 1;
	flag = 1;
	while (line[i])
	{
		if (line[i] == quotes)
			flag++;
		if (flag == 2)
			break ;
		i++;
	}
	if (flag != 2)
		i = quotes * -1;
	return (i);
}

int	check_command(char *line, int index)
{
	int	i;

	i = index - 1;
	while (line[++i] != '\0')
	{
		if (line[i] == 39 || line[i] == 34)
		{	
			i = skip_quotes(line, i, line[i]);
			if (i < 0)
				return (i);
		}
		if (is_whitespace(line[i]))
			return (i);
		if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			return (i - 1);
		if (line[i] == 59 || line[i] == 44 || line[i] == 92)
			return (line[i] * -1);
	}
	return (i);
}
