/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:20 by cgim              #+#    #+#             */
/*   Updated: 2022/06/04 21:29:51 by cgim             ###   ########.fr       */
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

int	skip_quote(char *cmd, int i)
{
	int	quote;

	quote = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			if (quote == 0)
			{
				if (cmd[i] == '"')
					quote = 2;
				else
					quote = 1;
			}
			else if ((cmd[i] == '"' && quote == 2) || (cmd[i] == '\'' && quote == 1))
				quote = 0;
			i++;
		}
		else if ((cmd[i] == '<' || cmd[i] == '>' || cmd[i] == ' ') && quote == 0)
			break;
		else
			i++;
	}
	return (i);
}

/* quote = 1 싱글 quote = 2 더블
 * redircetion 문자 > < 나 whitespace 나 \0 나오면 거기서 스탑
 * $문자 오면 환경변수 찾아서 조인해줘야하는 데 나중에 후처리하는 것을 처리하자
 * 일반문자 + 인용문 경우 붙어서 출력한다.
*/
int	skip_arg(char *cmd, int i)
{
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == ' ')
			break;
		else if (cmd[i] == '"' || cmd[i] == '\'')
			i = skip_quote(cmd, i);
		else
			i++;
	}
	return (i);
}

int	skip_redirection(char *cmd, int i)
{
	i++;
	if (cmd[i] == '<' || cmd[i] == '>')
		i++;
	if (cmd[i] == ' ')
		i = skip_whitespace(cmd, i);
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
// get_argv 관련 함수
// 환경변수도 같이 처리해야하는 것 같은데?


char	*get_arg(char *cmd, int i)
{
	char	*arg;
	int		index;

	index = skip_arg(cmd, i) - i;
	arg = (char *)malloc(sizeof(char) * (index + 1));
	if (arg == NULL)
		return (NULL);
	ft_memcpy(arg, cmd + i, index);
	arg[index] ='\0';
	return (arg);
}

int	get_argv(char **argv, char *cmd)
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
			argv[index] = get_arg(cmd, i);
			if (argv[index] == NULL)
			{
				while (--index >= 0)
					free(argv[index]);
				return (1);
			}
			printf("argv[%d]: %s\n", index, argv[index]);
			i = skip_arg(cmd, i);
			index++;
		}
	}
	return (0);
}

char **init_argv(char *cmd)
{
	char **argv;
	int	index;

	index = count_argv(cmd);
	printf("index: %d\n", index);
	argv = (char **)malloc(sizeof(char *) * (index + 1));
	if (argv == NULL)
		return (NULL);
	if (get_argv(argv, cmd))
	{
		free(argv);
		return (NULL);
	}
	argv[index] = NULL;
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
	/*
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
	}*/
	return (chunk);
}
