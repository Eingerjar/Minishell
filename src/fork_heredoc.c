/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:43:02 by haryu             #+#    #+#             */
/*   Updated: 2022/06/17 22:32:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global g_global;

void	clean_global(void)
{
	g_global.last_exitcode = 0;
	return ;
}

void	handler_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	g_global.last_exitcode = 1;
	exit(1);
}

char	*make_filename(int number_cmd, int index_cmd, char *dir)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(dir, TEMPFILE);
	temp2 = ft_strjoin(temp1, ft_itoa(number_cmd));
	free(temp1);
	temp1 = ft_strjoin(temp2, "_");
	free(temp2);
	temp2 = ft_strjoin(temp1, ft_itoa(index_cmd));
	free(temp1);
	return (temp2);
}

int	make_temp(char *directory, int *cmdnum)
{
	char	*tempfile;
	int		ret;

	tempfile = make_filename(cmdnum[0], cmdnum[1], directory);
	ret = open(tempfile, O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
	if (ret < 0)
	{
		printf("%sOPEN ERROR, %s", RED, strerror(errno));
		exit(1);
	}
	return (ret);
}

void	reset_integer_vector(int **vector, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		(*vector)[i] = 0;
	return ;
}


t_flist	*find_delimiter(int **cmd, t_flist **heredoc)
{
	t_flist	*temp;
	int		i;
	int		j;

	while (TRUE)
	{
		i = (*cmd)[0];
		if (heredoc[i]->next == NULL)
		{
			(*cmd)[0] += 1;
		}
		else
		{
			temp = heredoc[i]->next;
			break ;
		}
	}
	j = 0;
	while (j < (*cmd)[1])
	{
		temp = temp->next;
		j++;
	}
	return (temp);
}

void	check_delimiter(int **cmd, t_flist *delimiter, t_flist **heredoc, int maxlen)
{
	if (delimiter->next == NULL)
	{
		(*cmd)[0] += 1;
		(*cmd)[1] = 0;
	}
	else
	{
		(*cmd)[1] += 1;
		return ;
	}
	if ((*cmd)[0] == maxlen)
		return ;
	while (heredoc[(*cmd)[0]]->next == NULL)
	{
		(*cmd)[0] += 1;
		if ((*cmd)[0] == maxlen)
			break ;
	}
}

void	init_delimiter(int **cmd, t_flist **heredoc)
{
	while (TRUE)
	{
		if (heredoc[(*cmd)[0]]->next == NULL)
			(*cmd)[0] += 1;
		else
			break ;
	}
}

int	readline_heredoc(int fd, int **cmd, t_flist **heredoc, int height)
{
	t_flist	*delimiter;
	char	*line;
	char	*putin;
	int		len;

	delimiter = find_delimiter(cmd, heredoc);
	signal(SIGINT, handler_heredoc);
	len = 0;
	while (TRUE)
	{
		line = readline("> ");
		if (line == NULL)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(line, delimiter->name, ft_strlen(delimiter->name)) && \
ft_strlen(line) == ft_strlen(delimiter->name))
		{
			if (len == 0)
				write(fd, "\n", 1);
			break ;
		}
		putin = ft_strjoin(line, "\n");
		len += ft_strlen(putin);
		write(fd, putin, ft_strlen(putin));
		free(putin);
	}
	check_delimiter(cmd, delimiter, heredoc, height);
	return (FALSE);
}

void	child_heredoc(t_flist **heredoc, int height, char *installed)
{
	char	*directory;
	int		fd_temp;
	int		*cmdnum;

	clean_global();
	directory = ft_strjoin(installed, TEMP);
	cmdnum = malloc(sizeof(int) * 2);
	cmdnum[0] = 0;
	cmdnum[1] = 0;
	init_delimiter(&cmdnum, heredoc);
	while (TRUE)
	{
		fd_temp = make_temp(directory, cmdnum);
		if (readline_heredoc(fd_temp, &cmdnum, heredoc, height))
		{
			printf("%sheredoc Error\n", RED);
			g_global.last_exitcode = EXIT_FAILURE;
			exit(EXIT_FAILURE);
		}
		close(fd_temp);
		if (cmdnum[0] == height)
			exit (EXIT_SUCCESS);
	}
	exit (0);
}

void	fork_heredoc(t_flist **heredoc, int height, char *installed)
{
	pid_t	here_child;
	int		status;

	here_child = fork();
	if (here_child == -1)
		printf("%sfork error\n", RED);
	if (here_child == 0)
		child_heredoc(heredoc, height, installed);
	else
		wait(&status);
	g_global.last_exitcode = WEXITSTATUS(status);
	return ;
}
