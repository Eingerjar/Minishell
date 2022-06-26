/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_close_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:36:40 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 12:45:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_pipe(int **pipe, int height)
{
	int	i;

	i = -1;
	while (++i < height)
	{
		close(pipe[i][0]);
		close(pipe[i][1]);
	}
}
