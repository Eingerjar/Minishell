/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:20 by cgim              #+#    #+#             */
/*   Updated: 2022/06/03 21:57:22 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_chunk(t_chunk *chunk)
{
	int	i;

	i = -1;
	if (chunk->argv)
	{
		while (chunk->argv[++i])
			free(chunk->argv[i]);
	}
	if (chunk->input)
		free(chunk->input);
	if (chunk->output)
		free(chunk->output);
}

int	skip_whitespace(char *cmd, int i)
{
	while (cmd[i] == ' ')
		i++;
	return (i);
}

int	skip_arg(char *cmd, int i)
{
	int	quote;

	quote = 0;
	return (i);
}

int	skip_redirection(char *cmd, int i)
{
	i++;
	if (cmd[i] == '<' || cmd[i] == '>')
		i++;
	i = skip_arg(cmd, i);
	return (i);
}

int	count_argv(char *cmd)
{
	int	index;
	int	i;
	
	index = 0;
	i = 0;
	while (cmd[i] != '\0')
	{	
		if (cmd[i] == ' ')
			i = skip_whitespace(cmd, i);
		else if (cmd[i] == '<' || cmd[i] == '>')
			i = skip_redirection(cmd, i);
		else
		{
			i = skip_arg(cmd, i);
			index++;
		}
	}
	return (index);
}

char **init_argv(char *cmd)
{
	char **argv;
	int	index;

	index = count_argv(cmd);
	return (argv);
}

t_chunk *init_structure(int index, char **cmd)
{
	t_chunk	*chunk;
	
	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->argv = init_argv(cmd[index]);
	if (chunk->argv == NULL)
	{
		free_chunk(chunk);
		return (NULL);
	}
	chunk->input = init_input(cmd[index]);
	if (chunk->input == NULL)
	{
		free_chunk(chunk);
		return (NULL);
	}
	chunk->output = init_output(cmd[index]);
	if (chunk->output == NULL)
	{
		free_chunk(chunk);
		return (NULL);
	}
	return (chunk);
}
