#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	main(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 1)
		return (1);
	i = -1;
	args = (char **)malloc(argc * sizeof(char *));
	if (!args)
		return (1);
	args[argc - 1] = NULL;
	while (++i < argc - 1)
		args[i] = argv[i + 1];
	execve("/bin/echo", args, NULL);
	free(args);
	return (0);
}
