#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
	int i;

	if (argc < 2)
		return (0);
	i = 0;
	while(envp[i] != NULL)
	{
		printf("%s\n", argv[i]);
		printf("i:%d %s\n",i, envp[i]);
		i++;
	}
	return (0);
}
