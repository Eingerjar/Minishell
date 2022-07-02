/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_malloc_wrap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:15:10 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:34:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*malloc_wrap(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		printf("😭 Malloc Error. : %s\n", strerror(errno));
		g_global.last_exitcode = EXIT_FAILURE;
	}
	return (ret);
}
