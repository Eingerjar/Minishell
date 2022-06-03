/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welchs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:49:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 02:13:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern char **environ;

void	welchs_clear(void)
{
	char	*cmd;
	pid_t	pid;
	int		status;

	cmd = "/usr/bin/clear";
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, NULL, environ) == -1)
		{
			printf("%s\n", strerror(errno));
			exit(0);
		}
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return ;
}

void	welchs_sleep(void)
{
	char	*cmd;
	pid_t	pid;
	int		status;
	char	*line;
	char	**argv;

	cmd = "/bin/sleep";
	line = "/bin/sleep 1";
	argv = ft_split(line, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			printf("%s\n", strerror(errno));
			exit(0);
		}
	}
	else
		waitpid(pid, &status, WUNTRACED);
	free(argv);
	return ;

}

int welchs(void)
{
	char	*buffer;
	int		fd;
	int		cnt;

	buffer = malloc(sizeof(char) * 3001);
	if (!buffer)
		return (0);
	fd = open("./src/image_can", O_RDONLY);
	if (fd < 0)
		printf("%s\n", strerror(errno));
	cnt = read(fd, buffer, 3000);
	buffer[cnt] = 0;	
	if (cnt < 0)
		printf("%s\n", strerror(errno));
	printf("%s%s%s\n", PURPLE, buffer, WHITE);
	close(fd);
	free(buffer);
	welchs_sleep();
	welchs_clear();
	return (0);
}
