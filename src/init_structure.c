/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:20 by cgim              #+#    #+#             */
/*   Updated: 2022/06/24 11:50:32 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_flist	*get_redirection(char *cmd, int i)
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

static t_flist	*init_input(char *cmd)
{
	t_flist	*head;
	t_flist	*new;
	int		i;

	head = NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (is_whitespace(cmd[i]))
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

static t_flist	*init_output(char *cmd)
{
	t_flist	*head;
	t_flist	*new;
	int		i;

	head = NULL;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (is_whitespace(cmd[i]))
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
		print_error_exit("init_argv error\n");
	chunk->input = init_input(cmds[index]);
	chunk->output = init_output(cmds[index]);
	return (chunk);
}
