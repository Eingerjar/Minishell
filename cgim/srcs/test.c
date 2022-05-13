#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
		printf("Child: I will be exited\n");
	else
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		while (1)
			;
	}
	return (0);
}
