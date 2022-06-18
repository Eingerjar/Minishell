/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_reset_integer_vector.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:56:08 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:14:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

void	reset_integer_vector(int **vector, int length)
{
	int	i;

	i = -1;
	while (++i < length)
		(*vector)[i] = 0;
	return ;
}
