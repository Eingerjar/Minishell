/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:41 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 10:54:58 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	g_global;

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

void	init_process(char **installed, struct termios *new)
{
	(*installed) = ft_getcwd();
	g_global.home = getenv("HOME");
	g_global.heredir = ft_strjoin((*installed), TEMP);
	ft_init_env();
	ft_init_export();
	welchs(*installed);
	tcgetattr(0, &g_global.old_settings);
	init_tcsetattr(new);
	return ;
}

int	main(void)
{
	char			*installed;
	char			*line;
	char			*prompt;
	struct termios	new;

	init_process(&installed, &new);
	while (TRUE)
	{
		main_signal();
		prompt = current_prompt();
		line = readline(prompt);
		if (line)
		{
			add_history(line);
			tcsetattr(0, TCSANOW, &g_global.old_settings);
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
