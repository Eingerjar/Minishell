/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_welchs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:49:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 20:47:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*where_is_welches(char *install)
{
	char	*temp;
	char	*ret;

	temp = "/src/image_can";
	ret = ft_strjoin(install, temp);
	return (ret);
}

static void	ft_clear_screen(void)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		printf("\n");
		i++;
	}
}

int	welchs(char *installed)
{
	char	*buffer;
	char	*temp;
	int		fd;
	int		cnt;

	buffer = malloc_wrap(sizeof(char) * 3001);
	temp = where_is_welches(installed);
	fd = open(temp, O_RDONLY);
	if (fd < 0)
		printf("%s\n", strerror(errno));
	cnt = read(fd, buffer, 3000);
	buffer[cnt] = 0;
	if (cnt < 0)
		printf("%s\n", strerror(errno));
	printf("%s%s%s\n", PURPLE, buffer, WHITE);
	close(fd);
	free(buffer);
	free(temp);
	sleep(1);
	ft_clear_screen();
	return (FALSE);
}
