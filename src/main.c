/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:41 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 01:51:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern char	**environ;

char *ft_getcwd(void)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER);
	if (!buf)
		return (NULL);
	getcwd(buf, BUFFER);
	return (buf);
}

void handler_main(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

char *current_prompt(void)
{
	char	*ret;
	char	*middle;
	char	*temp;
	char	*front;
	char	*last;

	front = "\033[0;35m🥤 shell \033[0;36m\"";
	last = "\" \033[0;37m>> \n";
	middle = ft_getcwd();
	temp = ft_strjoin(CYAN, middle);
	free(middle);
	middle = ft_strjoin(front, temp);
	free(temp);
	ret = ft_strjoin(middle, last);
	free(middle);
	return (ret);
}

int main(void)
{
	char	*installed;
	char	*line;

	installed = ft_getcwd();
	signal(SIGINT, handler_main);
	welchs();
	while(1)
	{
		ft_unlink(installed);
		line = readline(current_prompt());
		if (line)
		{
			add_history(line);
			//printf("🖥  RC Shell @>>%s\n", line);
			if(!pre_error_check(line))
				printf("error ok! Lets make another function!\n");
			free(line);
			line = NULL;
		}
		else
		{
			printf("exit\n");
			exit(0);
		}
	}
	free(installed);
	return (0);
}
