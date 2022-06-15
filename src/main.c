/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:41 by haryu             #+#    #+#             */
/*   Updated: 2022/06/15 23:29:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	global;

char	*ft_getcwd(void)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER);
	if (!buf)
		return (NULL);
	getcwd(buf, BUFFER);
	return (buf);
}

void	handler_main(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

char	*current_prompt(void)
{
	char	*ret;
	char	*middle;
	char	*temp;
	char	*front;
	char	*last;

	front = "\033[0;35m🥤 shell \033[0;36m\"";
	last = "\" \033[0;37m\n>> ";
	middle = ft_getcwd();
	temp = ft_strjoin(CYAN, middle);
	free(middle);
	middle = ft_strjoin(front, temp);
	free(temp);
	ret = ft_strjoin(middle, last);
	free(middle);
	return (ret);
}

void	clean_line(char **line, char *tempdir)
{
	free(*line);
	(*line) = NULL;
	ft_unlink(tempdir);
	return ;
}

int	main(void)
{
	char	*installed;
	char	*line;

	installed = ft_getcwd();
	signal(SIGINT, handler_main);
	welchs();
	while (1)
	{
		line = readline(current_prompt());
		if (line)
		{
			add_history(line);
			if (ft_strlen(line) == 0)
				continue ;
			if (!pre_error_check(line))
			{
				heredoc_check(line, installed);
				sentence_part(line);
			}
			clean_line(&line, installed);
		}
		else
		{
			printf("😴 exit\n");
			exit(0);
		}
	}
}
