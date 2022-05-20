#include <stdio.h>

int main(int ac, char **av, char **ep)
{
	(void)ac;
	(void)av;
	while (*ep)
		printf("%s\n", *ep++);
	return (0);
}
