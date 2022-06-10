/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flistadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:46:57 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 19:46:58 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	flistadd_back(t_flist **head, t_flist *new)
{
	t_flist	*tmp;

	if ((*head) != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}
