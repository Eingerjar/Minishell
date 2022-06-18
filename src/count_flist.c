/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_flist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:16:49 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 22:21:29 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_flist(t_flist *flist)
{
	int	size;

	size = 0;
	while (flist)
	{
		size++;
		flist = flist->next;
	}
	return (size);
}
