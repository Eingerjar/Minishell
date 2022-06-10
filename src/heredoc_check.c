/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:33:56 by haryu             #+#    #+#             */
/*   Updated: 2022/06/11 00:38:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	global;

static char	*ft_strndup(char *line, size_t byte)
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

void	make_flist(int start, int end, char *line, t_flist **target)
{
	t_flist	*temp;
	t_flist	*copy;

	copy = (*target);
	temp = malloc(sizeof(t_flist) * 1);
	if (!temp)
	{
		printf("heredoc init error\n");
		exit(1);
	}
	temp->next = 0;
	temp->type = 1;
	temp->name = ft_strndup(line + start, (size_t)(end - start));
	while (TRUE)
	{
		if (copy->next == 0)
			break ;
		copy = copy->next;
	}
	copy->next = temp;
	return ;
}

int	check_redirection_heredoc(char *line, int index, \
int redirection, t_flist **target)
{
	int	priv;
	int	next;

	next = 0;
	if (redirection == 60 && line[index + 1] == 60)
	{
		index += 2;
		while (line[index] == ' ')
			index++;
		priv = index;
		next = check_command(line, priv);
		make_flist(priv, next, line, target);
	}
	else
		return (check_redirection(line, index, redirection));
	return (next);
}

void	make_heredoc(char *line, t_flist **target)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 60 || line[i] == 62)
			i = check_redirection_heredoc(line, i, line[i], target);
		else if (line[i] == ' ')
			continue ;
		else
			i = check_command(line, i);
		if (!line[i])
			break ;
	}
}

void	init_flist(t_flist ***target, int height)
{
	int	i;

	(*target) = malloc(sizeof(t_flist *) * (height));
	if (!(*target))
	{
		printf("heredoc init error\n");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		(*target)[i] = malloc(sizeof(t_flist) * 1);
		if (!(*target)[i])
		{
			printf("heredoc init error\n");
			exit(1);
		}
		(*target)[i]->name = 0;
		(*target)[i]->next = 0;
		(*target)[i]->type = 0;
		i++;
	}
	// (*target)[height] = 0;
}

t_flist	**pre_heredoc(char **chunks, int height)
{
	t_flist	**ret;
	int		i;

	i = 0;
	init_flist(&ret, height);
	while (i < height)
	{
		make_heredoc(chunks[i], &ret[i]);
		i++;
	}
	return (ret);
}

void	free_heredoc_part(t_flist **heredoc)
{
	t_flist	*temp;
	t_flist *next;

	while (1)
	{
		temp = (*heredoc);
		if (temp->next == 0)
			break ;
		next = temp->next;
		(*heredoc) = next;
		free(temp->name);
		free(temp);
		temp = 0;
	}
}

void	free_heredoc(t_flist **heredoc, int height)
{
	int	i;

	i = height;
	while (--i >= 0)
	{
		if (heredoc[i]->next != 0)
			free_heredoc_part(&(heredoc[i]->next));
		free(heredoc[i]);
	}
	free(heredoc);
	return ;
}
// int	fork_heredoc(t_flist **chunks, int height)
// {
// 	pid_t	child;
// 	int		status;

// 	1. signal 처리 방법 지정 
// 	2. fork 진행 
// 	3. 지정된 디리미터 들어오기 전까지 저장하는 구조 작성
// 	4. 파일 저장 이름 만들어 저장하기 파트 작성 
// }

int heredoc_check(char *line)
{
	char	**chunks;
	int		chunk_height;
	t_flist	**heredoc;

	chunks = vertical_split(line);
	chunk_height = check_height(line);
	print_chunks(chunks, chunk_height);
	heredoc = pre_heredoc(chunks, chunk_height);
	print_heredoc_lst(heredoc, chunk_height);
	// fork_heredoc(heredoc, chunk_height);
	free_heredoc(heredoc, chunk_height);
	chunk_free(chunks, chunk_height);
	return (FALSE);
}