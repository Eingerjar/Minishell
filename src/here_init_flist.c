/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_init_flist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:06:03 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_flist(t_flist ***target, int height)
{
	int	i;

	(*target) = malloc_wrap(sizeof(t_flist *) * (height));
	i = 0;
	while (i < height)
	{
		(*target)[i] = malloc_wrap(sizeof(t_flist) * 1);
		(*target)[i]->name = 0;
		(*target)[i]->next = 0;
		(*target)[i]->type = 0;
		i++;
	}
}
