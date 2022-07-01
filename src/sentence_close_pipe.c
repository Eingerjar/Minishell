/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence_close_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:36:40 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 21:48:17 by haryu            ###   ########.fr       */
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
		free(pipe[i]);
	}
	free(pipe);
}
