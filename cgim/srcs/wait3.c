#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

int	main(void)
{
	struct rusage	ru;
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child Process\n");
		return (0);
	}
	else
	{
		wait3(NULL, 0, &ru);
		printf("Parent Process\n");
		printf("=========Resource Usage of Child========\n");
		printf("Number of Context Switch (Voluntary)\t%ld\n", ru.ru_nvcsw);
		printf("Number of Context Switch (Involuntary)\t%ld\n", ru.ru_nivcsw);
		printf("Number of Page Swap\t%ld\n", ru.ru_nswap);
		printf("Number of Page Fault\t%ld\n", ru.ru_majflt);
		printf("Signal Received\t%ld\n", ru.ru_nsignals);
	}
	return (0);
}
