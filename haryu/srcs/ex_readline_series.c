#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * 컴파일 시 -l, -I, -L 설정을 해줘야 한다. 
 * */

void handler(int signum)
{
    if (signum != SIGINT)
        return;
	printf("\n");
	rl_replace_line("^C", 1);
	rl_on_new_line();
    rl_replace_line("", 1);
    rl_redisplay();
}

int main(void)
{
    int ret;
    char *line;

	ret = 1;
    signal(SIGINT, handler);
    while (1)
    {
        line = readline("Jarvis :");
        if (line)
        {
            if (ret)
                printf("Jarvis :%s\n", line);
            add_history(line);
            free(line);
            line = NULL;
        }
        else
        {
            printf("ctrl + d\n");
			exit(0);
        }
    }
    return (0);
}
