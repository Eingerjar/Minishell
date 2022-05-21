#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

void	open_and_write(int *pipe, int argc, char **argv)
{
	int	i;
	int	fd;
	char buffer[1000];
	int	check;


	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			exit(1);
		check = read(fd, buffer, 1000);
		while (check > 0)
		{
			write(pipe[1], buffer, check);
			check = read(fd, buffer, 1000);
		}
		if (check == -1)
			exit(1);
		close(fd);
	}
}

int main(int argc, char **argv)
{
	pid_t pid;
	int fd[2];
	char *args[] = {"cat", 0};
	int status;

	if (argc < 2)
	{
		printf("< file1 ...\n");
		return (0);
	}
	if (pipe(fd) == -1)
	{
		printf("pipe error\n");
		return (1);
	}
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		sleep(1);
		open_and_write(fd, argc, argv);
		dup2(fd[0], 0);
		close(fd[1]);
		execve("/bin/cat", args, NULL);
	}
	else
	{
		close(fd[1]);
		printf("CHLD PID: %d\n", pid);
		wait(&status);
		printf("end child process\n");
	}
	return (0);
}
