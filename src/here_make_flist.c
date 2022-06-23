/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_flist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:57:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strndup(char *line, size_t byte)
{
	char	*ret;
	size_t	i;

	ret = malloc_wrap(sizeof(char) * (byte + 1));
	i = 0;
	while (i < byte)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	make_flist(int start, int end, char *line, t_flist **target)
{
	t_flist	*temp;
	t_flist	*copy;

	copy = (*target);
	temp = malloc_wrap(sizeof(t_flist) * 1);
	temp->next = 0;
	temp->type = 1;
	temp->name = ft_strndup(line + start, (size_t)(end - start));
	while (TRUE)
	{
		if (copy->next == 0)
			break ;
		copy = copy->next;
	}
	copy->next = temp;
	return ;
}
