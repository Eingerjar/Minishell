/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pipelines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:38:45 by haryu             #+#    #+#             */
/*   Updated: 2022/05/19 18:54:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/**
 * @brief For pipe line, make child process test
 * @return
 */

void	child_process(char **argv, char **envp, int **fd, int index)
{
	(void)argv;
	(void)envp;
	printf("You are child Number %d, Your pipe %d %d\n", index, fd[index][0], fd[index][1]);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int		len;
	int		i;
	int		**fd;
	pid_t	pid;

	(void)argc;
	len = atoi(argv[1]);
	printf("len : %d\n", len);
	fd = malloc(sizeof(int *) * len);
	if (!fd)
		return (2);
	i = 0;
	while (i < len)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (pipe(fd[i]) == -1)
		{
			printf("Pipe Error!\n");
			return (2);
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		pid = fork();
		if (pid == 0)
			break ;
		i++;
	}
	if (pid == 0)
		child_process(argv, envp, fd, i);
	waitpid(pid, NULL, 0);
	if (i + 1 == len)
		printf("All child is dead.\n");
	return (0);
}
