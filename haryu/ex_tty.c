#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*d;

	fd = ttyslot();
	if (isatty(fd))
		printf("aaa\n");
	d = ttyname(fd);
	printf("d - %s\n", d);
}