/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welchs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:49:47 by haryu             #+#    #+#             */
/*   Updated: 2022/06/03 19:20:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	return (0);
}
