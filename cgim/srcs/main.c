#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <libft.h>


void	pharse_and_process(char *str)
{
	char **chunks;
	int i;
	pid_t pid;
	char **argv;
	int	**fd;

	chunks = ft_split(str, '|');
	argv = cmd
	free(str);
	i = -1;
	while (chunks[++i] != NULL)
	{
		pid = fork();
		if (pid == 0)
			break ;
	}
	if (pid == 0)
	{
		if (i == 0)
		{
			str = readline("prompt :");
			printf("child heredoc: %s\n", str);
		}
		execve("\bin\sleep", argv, NULL);
	}
}

void	handler(int signum)
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
	int		check;
	char	*str;

	check = 1;
	signal(SIGINT, handler);
	while (1)
	{
		str = readline("prompt :");
		if (str)
		{
			if (check && *str != 0)
				pharse_and_process(str);
			add_history(str);
			free(str);
			str = NULL;
		}
		else
		{
			printf("ctrl + d\n");
			exit(0);
		}
	}
}
