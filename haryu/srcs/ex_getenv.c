#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("HOSTNAME = %s\n", getenv("HOSTNAME"));
	printf("TERM     = %s\n", getenv("TERM"));
	printf("SHELL    = %s\n", getenv("SHELL"));
	printf("QTDIR    = %s\n", getenv("QTDIR"));
	printf("HOME     = %s\n", getenv("HOME"));
	printf("LANG     = %s\n", getenv("LANG"));
	return (0);
}
