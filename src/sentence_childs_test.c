/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_childs_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:41:07 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:33:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	childs_test(int height, char **chunks, int **pipes)
{
	int	i;

	i = 0;
	write(pipes[height - 1][1], "child process test!\n", \
ft_strlen("child process test!\n"));
	while (i < height)
	{
		printf("pipe : %d %d\n", pipes[i][0], pipes[i][1]);
		i++;
	}
	print_chunks(chunks, height);
	exit(0);
}
