#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	for(int i = 1; i < ac; i++)
	{
		int ret = printf("%10d : %s\n",i, av[i]);
		printf("str length : %3lu(%d)\n", strlen(av[i]), ret);
	}
	return (0);
}
