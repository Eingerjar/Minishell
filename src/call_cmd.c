/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:58:34 by cgim              #+#    #+#             */
/*   Updated: 2022/06/25 19:25:31 by cgim             ###   ########.fr       */
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
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	exit(1);
}

static void	execute_process(char **argv)
{
	char	**path;
	char	*tmp;
	char	*cmd;
	int		i;

	i = -1;
	execve(argv[0], argv, NULL);
	cmd = ft_strdup(argv[0]);
	if (cmd == NULL)
		print_error_exit("ft_strdup malloc error\n");
	path = ft_split(getenv("PATH"), ':');
	if (path == NULL)
		print_error_exit("PATH ft_split error\n");
	while (path[++i])
	{
		tmp = get_cmd(path[i], cmd);
		free(argv[0]);
		argv[0] = tmp;
		execve(argv[0], argv, NULL);
	}
	print_cmd_exit(cmd);
}

void	call_cmd(int index, char **cmd, int **pipe)
{
	t_chunk	*chunk;
	int		cmd_size;

	cmd_size = count_cmd(cmd);
	chunk = init_structure(index, cmd);
	close_other_pipe(index, cmd, pipe);
	set_stdin(pipe, index, chunk->input);
	set_stdout(pipe, index, cmd_size, chunk->output);
	execute_process(chunk->argv);
}
