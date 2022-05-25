/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:35:34 by cgim              #+#    #+#             */
/*   Updated: 2021/12/01 14:30:50 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*tmp;
	t_list	*p;

	if (lst == 0)
		return (0);
	init = ft_lstnew(f(lst->content));
	if (init == 0)
		return (0);
	lst = lst->next;
	p = init;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == 0)
			ft_lstclear(&init, del);
		ft_lstadd_back(&p, tmp);
		lst = lst->next;
	}
	return (init);
}
