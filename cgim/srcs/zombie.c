#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		printf("error_fork\n");
		return (0);
	}
	else if (!pid)
	{
		printf("child will be exit\n");
		return (0);
	}
	else
	{
		sleep(1);
		printf("just parent: %d\n", pid);
		return (0);
	}
}
