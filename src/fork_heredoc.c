/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:43:02 by haryu             #+#    #+#             */
/*   Updated: 2022/06/12 21:04:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global global;

void	clean_global(void)
{
	global.last_exitcode = 0;
	return ;
}

void	handler_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;	
	global.last_exitcode = 1;
	return ;
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
	ret = open(tempfile, O_CREAT | O_RDWR | O_APPEND);
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
	while(++i < length)
		(*vector)[i] = 0;
	return ;
}

char	*find_delimiter(int **cmd, t_flist **heredoc)
{
	int		i;
	int		j;
	t_flist	*temp;

	i = (*cmd)[0];
	j = 0;
	if ((*heredoc)[i].next != 0)
		temp = (*heredoc)[i].next;
	else
	{
		(*cmd)[0] += 1;
		(*cmd)[1] = 0;
		i = (*cmd)[0];
		return (find_delimiter(cmd, heredoc));
	}
	while(j < (*cmd)[1])
	{
		temp = temp->next;
		j++;
	}
	if (temp->next == 0)
	{
		(*cmd)[0] += 1;
		(*cmd)[1] = 0;
	}
	(*cmd)[1] += 1;
	return(temp->name);
}

int	readline_heredoc(int fd, int *cmd, t_flist **heredoc)
{
	char	*delimiter;
	char	*line;
	char	*putin;

	delimiter = find_delimiter(&cmd, heredoc);
	signal(SIGINT, handler_heredoc);
	while(1)
	{
		line = readline(">");
		if (global.last_exitcode == 1)
		{
			global.last_exitcode = 0;
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			exit (1);
		}
		if (line == NULL)
			line = ft_strdup("");
		printf("%scompare :\n%s(%d)\n%s(%d)\n", CYAN, line, (int)ft_strlen(line), delimiter, (int)ft_strlen(delimiter));
		if (!ft_strncmp(line, delimiter, ft_strlen(delimiter)) && ft_strlen(line) == ft_strlen(delimiter))
			break ;
		putin = ft_strjoin(line, "\n");
		write(fd, putin, ft_strlen(putin));
		free(putin);
	}
	printf("finish\n");
	return (FALSE);
}

void	child_heredoc(t_flist **heredoc, int height, char *installed)
{
	char	*directory;
	int		fd_temp;
	int		cmdnum[2];

	clean_global();
	directory = ft_strjoin(installed, TEMP);
	cmdnum[0] = 0;
	cmdnum[1] = 0;
	while(1)
	{
		if (global.last_exitcode == 1)
			break ;
		fd_temp = make_temp(directory, cmdnum);
		if (readline_heredoc(fd_temp, cmdnum, heredoc))
		{
			printf("%sheredoc Error\n", RED);
			exit(1);
		}
		close(fd_temp);
		if (cmdnum[0] == height)
			exit (0);
	}
	exit (0);
}

void	fork_heredoc(t_flist **heredoc, int height, char *installed)
{
	pid_t	here_child;
	int		status;

	signal(SIGINT, handler_heredoc);
	here_child = fork();
	if (here_child == -1)
		printf("%sfork error\n", RED);
	if (here_child == 0)
		child_heredoc(heredoc, height, installed);
	else
		if (wait(&status) == -1)
			global.last_exitcode = WEXITSTATUS(status);
	return ;
	
		/* 1. prepare signal 
		 * 2. fork - wait
		 * 0. child : 
		 * 1. exit code 초기화 
		 * 2. file name create(반복 시작)
		 * 2. append mode file create
		 * 3. line 받기 시작
		 * 4. delimitter check 
		 * 5. delimitter check ok -> break(파일 저장 및 fd close)
		 * 6. No -> write 무한 진행
		 *
		 * */
}
