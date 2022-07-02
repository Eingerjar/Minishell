/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:41 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 11:14:13 by haryu            ###   ########.fr       */
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

void	ctrld_leaks(void)
{
	printf("😴 exit : leaks check\n");
	system("leaks minishell");
	exit(EXIT_SUCCESS);
}

void	init_process(char **installed)
{
	(*installed) = ft_getcwd();
	g_global.home = getenv("HOME");
	g_global.heredir = ft_strjoin((*installed), TEMP);
	ft_init_env();
	ft_init_export();
	welchs(*installed);
	tcgetattr(0, &g_global.old_settings);
	return ;
}

int	main(void)
{
	char			*installed;
	char			*line;
	char			*prompt;
	struct termios	new;

	init_process(&installed);
	while (TRUE)
	{
		init_tcsetattr(&new);
		prompt = current_prompt();
		line = readline(prompt);
		if (line)
		{
			add_history(line);
			back_tcsetattr(&new);
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
