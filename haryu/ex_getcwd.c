#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char	*buf;
	size_t	size;

	size = 1024;
	buf = (char *)malloc(sizeof(char) * size);
	chdir("./");
	getcwd(buf, size);
	printf("getcwd : %s\n", buf);
	free(buf);
	return (0);
}