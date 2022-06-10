/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:20 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 10:19:44 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

//error_exit
void	print_error_exit(char *err_msg)
{
	int	size;

	size = ft_strlen(err_msg);
	write(2, err_msg, size);
	exit(1);
}

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
	if (cmd[i] == '"')
		q = 2;
	else
		q = 1;
	i++;
	while (q != 0)
	{
		if ((cmd[i] == '"' && q == 2) || (cmd[i] == '\'' && q == 1))
			q = 0;
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
			index += 1;
		}
	}
	return (index);
}
// get_argv 관련 함수
// 환경변수도 같이 처리해야하는 것 같은데?

int	skip_env(char *str, int i)
{
	i++;
	if (str[i] == '?' || ft_isdigit(str[i]))
		return (i + 1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == '_')
			i++;
		else
			break ;
	}
	return (i);
}

char	*get_env(char *str, int i)
{
	char	*env;
	int		index;

	index = skip_env(str, i) - i;
	env = (char *)malloc(sizeof(char) * index);
	if (env == NULL)
		return (NULL);
	ft_memcpy(env, str + i + 1, index - 1);
	env[index - 1] = '\0';
	return (env);
}

int	count_env_val(char *str, int i)
{
	int		cnt;
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		env = ft_itoa(g_status);
		if (env == NULL)
			print_error_exit("ft_itoa malloc error\n");
		return (ft_strlen(ft_itoa(g_status)));
	}
	if (ft_isdigit(str[i + 1]))
		return (0);
	env = get_env(str, i);
	if (env == NULL)
		print_error_exit("get_env error\n");
	env_val = getenv(env);
	if (env_val == NULL)
		cnt = 0;
	else
		cnt = ft_strlen(env_val);
	free(env);
	return (cnt);
}

// quote와double quote 경우 안의 환경변수 변환 해준다.
int	count_quote(char *str, int i)
{
	int	cnt;
	int	q;

	cnt = 0;
	if (str[i] == '"')
		q = 2;
	else
		q = 1;
	i++;
	while (q != 0)
	{
		if ((str[i] == '"' && q == 2) || (str[i] == '\'' && q == 1))
			q = 0;
		else if (str[i] == '$' && q == 2)
		{
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else
			cnt++;
		i++;
	}
	return (cnt);
}

int	count_env_val_and_quote(char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			cnt += count_quote(str, i);
			i = skip_quote(str, i);
		}
		else
		{
			i++;
			cnt++;
		}
	}
	return (cnt);
}

void	copy_env_val(char *dst, char *str, int i, int cnt)
{
	char	*env;
	char	*env_val;

	if (str[i + 1] == '?')
	{
		env_val = ft_itoa(g_status);
		if (env_val == NULL)
			print_error_exit("ft_itoa malloc error\n");
		ft_memcpy(dst + cnt, str + i + 1, ft_strlen(env_val));
		return ;
	}
	if (ft_isdigit(str[i + 1]))
		return ;
	env = get_env(str, i);
	if (env == NULL)
		print_error_exit("get_env error\n");
	env_val = getenv(env);
	free(env);
	if (env_val == NULL)
		return ;
	else
		ft_memcpy(dst + cnt, env_val, ft_strlen(env_val));
}

void	copy_quote(char *dst, char *str, int i, int cnt)
{
	int	q;

	if (str[i] == '"')
		q = 2;
	else
		q = 1;
	i++;
	while (q != 0)
	{
		if ((str[i] == '"' && q == 2) || (str[i] == '\'' && q == 1))
			q = 0;
		else if (str[i] == '$' && q == 2)
		{
			copy_env_val(dst, str, i, cnt);
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else
		{
			dst[cnt] = str[i];
			cnt++;
		}
		i++;
	}
}

void	copy_env_val_and_quote(char *dst, char *src)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '$')
		{
			copy_env_val(dst, src, i, cnt);
			cnt += count_env_val(src, i);
			i = skip_env(src, i);
		}
		else if (src[i] == '"' || src[i] == '\'')
		{
			copy_quote(dst, src, i, cnt);
			cnt += count_quote(src, i);
			i = skip_quote(src, i);
		}
		else
		{
			dst[cnt++] = src[i];
			i++;
		}
	}
}

char	*convert_env_and_quote(char	*str)
{
	char	*ret;
	int		index;

	index = count_env_val_and_quote(str);
	ret = (char *)malloc(sizeof(char) * (index + 1));
	if (ret == NULL)
		return (NULL);
	copy_env_val_and_quote(ret, str);
	ret[index] = '\0';
	return (ret);
}

char	*get_arg(char *cmd, int i)
{
	char	*arg;
	char	*ret;
	int		index;

	index = skip_arg(cmd, i) - i;
	arg = (char *)malloc(sizeof(char) * (index + 1));
	if (arg == NULL)
		print_error_exit("get_arg malloc error\n");
	ft_memcpy(arg, cmd + i, index);
	arg[index] = '\0';
	ret = convert_env_and_quote(arg);
	return (ret);
}

char	**get_argv(char *cmd, int size)
{
	char	**argv;
	int		index;
	int		i;

	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (argv == NULL)
		print_error_exit("\n");
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
			printf("%s\n", argv[index]);
			i = skip_arg(cmd, i);
			index++;
		}
	}
	return (argv);
}

char	**init_argv(char *cmd)
{
	char	**argv;
	int		index;

	index = count_argv(cmd);
	printf("index: %d\n", index);
	argv = get_argv(cmd, index);
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
				print_error_exit("intput get_redirection error\n");
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
				print_error_exit("output get_redirection error\n");
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
	chunk->output = init_output(cmds[index]);
	return (chunk);
}
