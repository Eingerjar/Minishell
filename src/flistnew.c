/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flistnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:46:22 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 19:46:23 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_flist	*flistnew(char type, char *name)
{
	t_flist	*p;

	p = (t_flist *)malloc(sizeof(t_flist));
	if (p == NULL)
		return (p);
	p->type = type;
	p->name = name;
	p->next = NULL;
	return (p);
}
