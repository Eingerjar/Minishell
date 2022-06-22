/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_doublestr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:26:28 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:26:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_doublestr(char ***target, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free((*target)[i]);
	free((*target));
}
