/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_final_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:38:51 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:33:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	final_print(int **pipe, int height)
{
	int		cnt;
	char	buff[3];

	cnt = read(pipe[height - 1][0], buff, 1);
	if (cnt != 0)
		write(1, buff, 1);
	while (cnt)
	{
		cnt = read(pipe[height - 1][0], buff, 1);
		if (cnt <= 0)
			break ;
		write(1, buff, 1);
	}
	return (FALSE);
}
