#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	pid2;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		usleep(50000);
		printf("Child1: I am the 1st Child\n");
		return (2);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		else if (!pid2)
		{
			usleep(49000);
			printf("Child2: I am the 2nd Child\n");
			return (3);
		}
		else
		{
			printf("Parent: I have 2 Children\n");
			ret = waitpid(pid, &status, 0);
			printf("Parent: Successfully got status from %d Child\n", ret);
			printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
			ret = waitpid(pid2, &status, 0);
			printf("Parent: Successfully got status from %d Child\n", ret);
			printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
		}
	}
	return (0);
}
