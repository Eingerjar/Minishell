/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:20 by cgim              #+#    #+#             */
/*   Updated: 2022/06/05 22:05:24 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	p_status = 0;
//free_part
void	*free_chunk(t_chunk *chunk)
{
	int	i;

	if (chunk == NULL)
		return (NULL);
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
	return (NULL);
}

void	*free_flist(t_flist *flist)
{
	if (flist == NULL)
		return (NULL);
	if (flist->name != NULL)
		free(flist->name);
	free(flist);
	return (NULL);
}

//parsing
int	skip_whitespace(char *cmd, int i)
{
	while (cmd[i] == ' ')
		i++;
	return (i);
}

int	skip_quote(char *cmd, int i)
{
	int	q;

	q = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			if (q == 0)
			{
				if (cmd[i] == '"')
					q = 2;
				else
					q = 1;
			}
			else if ((cmd[i] == '"' && q == 2) || (cmd[i] == '\'' && q == 1))
				q = 0;
			i++;
		}
		else if ((cmd[i] == '<' || cmd[i] == '>' || cmd[i] == ' ') && q == 0)
			break ;
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
			break ;
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

int	skip_env(char *str, int i)
{
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == '_')
			i++;
		else
			break;
	}
	return (i);
}

int	cout_env_val(char *str, int i)
{
	int		cnt;
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		return (ft_strlen(ft_itoa(p_status)));
	}
	env = (char *)malloc(sizeof(char) * (skip_env(str, i) - i));
	cnt = ft_strlen(env_val);
	return (cnt);
}

int	count_env_and_quote(char *str)
{
	int	cnt;
	int	i;
	int	quote;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			cnt += cout_env_val(str, i);
			i = skip_env(str, i);
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
		}
		else
		{
			i++;
			cnt++;
		}
	}
	return (cnt);
}

char	*conver_env_and_quote(char	*str)
{
	char	*ret;
	int		index;

	index = count_env_and_quote(str);
	ret = (char *)malloc(sizeof(char) * (index + 1));
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*get_arg(char *cmd, int i)
{
	char	*arg;
	int		index;

	index = skip_arg(cmd, i) - i;
	arg = (char *)malloc(sizeof(char) * (index + 1));
	if (arg == NULL)
		return (NULL);
	ft_memcpy(arg, cmd + i, index);
	arg[index] = '\0';
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
			i = skip_arg(cmd, i);
			index++;
		}
	}
	return (0);
}

char	**init_argv(char *cmd)
{
	char	**argv;
	int		index;

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

//flist funcs
t_flist	*flistnew(char type, char *name)
{
	t_flist	*p;

	p = (t_flist *)malloc(sizeof(t_flist));
	if (p == NULL)
		return (p);
	p->type = type;
	p->name = name;
	p->next = NULL;
	return (p);
}

void	flistadd_back(t_flist **head, t_flist *new)
{
	t_flist	*tmp;

	if ((*head) != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}

//intput 
t_flist	*get_redirection(char *cmd, int i)
{
	t_flist	*new;
	char	type;
	char	*name;

	i++;
	type = 0;
	if (cmd[i] == '<' || cmd[i] == '>')
	{
		type = 1;
		i++;
	}
	name = get_arg(cmd, i);
	if (name == NULL)
		return (NULL);
	new = flistnew(type, name);
	if (new == NULL)
	{
		free(name);
		return (NULL);
	}
	return (new);
}

t_flist	*init_input(char *cmd)
{
	t_flist	*head;
	t_flist	*new;
	int		i;

	head = NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
			i = skip_whitespace(cmd, i);
		else if (cmd[i] == '<')
		{
			new = get_redirection(cmd, i);
			if (new == NULL)
				return (free_flist(head));
			printf("input type:%d name:%s\n", new->type, new->name);
			flistadd_back(&head, new);
			i = skip_redirection(cmd, i);
		}
		else if (cmd[i] == '>')
			i = skip_redirection(cmd, i);
		else
			i = skip_arg(cmd, i);
	}
	return (head);
}

t_flist	*init_output(char *cmd)
{
	t_flist	*head;
	t_flist	*new;
	int		i;

	head = NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
			i = skip_whitespace(cmd, i);
		else if (cmd[i] == '>')
		{
			new = get_redirection(cmd, i);
			if (new == NULL)
				return (free_flist(head));
			printf("output type:%d name:%s\n", new->type, new->name);
			flistadd_back(&head, new);
			i = skip_redirection(cmd, i);
		}
		else if (cmd[i] == '<')
			i = skip_redirection(cmd, i);
		else
			i = skip_arg(cmd, i);
	}
	return (head);
}

t_chunk	*init_structure(int index, char **cmds)
{
	t_chunk	*chunk;

	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->argv = init_argv(cmds[index]);
	if (chunk->argv == NULL)
		return (free_chunk(chunk));
	chunk->input = init_input(cmds[index]);
	if (chunk->input == NULL)
		return (free_chunk(chunk));
	chunk->output = init_output(cmds[index]);
	if (chunk->output == NULL)
		return (free_chunk(chunk));
	return (chunk);
}
