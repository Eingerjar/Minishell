/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:16:22 by haryu             #+#    #+#             */
/*   Updated: 2022/06/02 01:34:16 by haryu            ###   ########.fr       */
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

int main(void)
{
	char	*installed;
	char	*line;

	installed = ft_getcwd();

	signal(SIGINT, handler_main);
	while(1)
	{
		ft_unlink(installed);
		line = readline("🖥   RC Shell :");
		if (line)
		{
			add_history(line);
			printf("🖥   RC Shell :%s\n", line);
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
