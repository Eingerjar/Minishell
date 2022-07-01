/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_flist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:57:15 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 21:31:34 by haryu            ###   ########.fr       */
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
	if (line[start] == '"' || line[start] == '\'')
	{
		end = skip_quotes(line, start, line[start]) - 1;
		start++;
	}
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
