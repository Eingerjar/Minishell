#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	for (int i = 0; i < ac; i++)
		printf("%s  ", av[i]);
	printf("\n");
	char *str;
	str = "$USER";
	av[0] = str;
	printf("%s\n", av[0]);
	return (0);
}
