/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:41 by haryu             #+#    #+#             */
/*   Updated: 2022/06/19 21:12:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	g_global;

void	handler_main(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	clean_line(char **line, char *tempdir, char *currentdir)
{
	free(*line);
	(*line) = NULL;
	free(currentdir);
	currentdir = NULL;
	ft_unlink(tempdir);
	return ;
}

void	ctrld(void)
{
	printf("😴 exit\n");
	exit(EXIT_SUCCESS);
}

void	init_process(char **installed)
{
	(*installed) = ft_getcwd();
	g_global.home = getenv("HOME");
	g_global.heredir = ft_strjoin((*installed), TEMP);
	welchs(*installed);

	return ;
}

int	main(void)
{
	char	*installed;
	char	*line;
	char	*prompt;

	init_process(&installed);
	while (TRUE)
	{
		signal(SIGINT, handler_main);
		prompt = current_prompt();
		line = readline(prompt);
		if (line)
		{
			add_history(line);
			if (ft_strlen(line) == 0)
				continue ;
			if (!pre_error_check(line))
			{
				if (!heredoc_check(line, installed))
					sentence_part(line);
			}
			clean_line(&line, installed, prompt);
		}
		else
			ctrld();
	}
}
