/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:58:34 by cgim              #+#    #+#             */
/*   Updated: 2022/07/05 20:52:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cmd(char *path, char *cmd)
{
	char	*ret;
	int		size;

	size = ft_strlen(path) + ft_strlen(cmd) + 2;
	ret = (char *)malloc(sizeof(char) * size);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, path, size);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, cmd, size);
	return (ret);
}

static void	print_cmd_exit(char *cmd)
{
	write(2, "😤 ", ft_strlen("😤 "));
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	g_global.last_exitcode = 127;
	exit(127);
}

static char	**copy_argv(char **argv)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
		i++;
	ret = malloc_wrap(sizeof(char *) * i);
	j = 0;
	while (j < i)
	{
		ret[j] = ft_strdup(argv[j]);
		j++;
	}
	return (ret);
}

static void	execute_process(char **argv)
{
	char	**path;
	char	**argv_copy;
	char	*tmp;
	int		i;

	i = -1;
	argv_copy = copy_argv(argv);
	if (argv[0][0] != '.')
	{
		tmp = ft_get_env("PATH");
		if (!tmp)
			print_cmd_exit(argv[0]);
		path = ft_split(tmp, ':');
		free(tmp);
		while (path[++i])
		{
			tmp = get_cmd(path[i], argv_copy[0]);
			free(argv[0]);
			argv[0] = tmp;
			execve(argv[0], argv, g_global.wel_env);
		}
	}
	else
		execve(argv_copy[0], argv_copy, g_global.wel_env);
	print_cmd_exit(argv_copy[0]);
}

void	call_cmd(int index, char **cmd, t_chunk *chunk, int **pipe)
{
	int		cmd_size;

	call_cmd_signal();
	cmd_size = count_cmd(cmd);
	close_other_pipe(index, cmd, pipe);
	if (cmd_size == 1 && is_builtin(chunk) && \
			!builtin_pro_or_not(chunk->argv))
	{
		set_stdout(pipe, index, cmd_size, chunk->output);
		execute_builtin(chunk->argv);
		return ;
	}
	set_stdin(pipe, index, chunk->input);
	set_stdout(pipe, index, cmd_size, chunk->output);
	if (is_builtin(chunk))
	{
		execute_builtin(chunk->argv);
		exit(0);
	}
	execute_process(chunk->argv);
}
