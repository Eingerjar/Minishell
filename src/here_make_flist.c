/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_flist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:57:15 by haryu             #+#    #+#             */
/*   Updated: 2022/07/04 17:42:32 by haryu            ###   ########.fr       */
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

static void	ft_flist_add_back(t_flist **target, t_flist **temp)
{
	t_flist	*copy;

	copy = (*target);
	while (TRUE)
	{
		if (copy->next == 0)
			break ;
		copy = copy->next;
	}
	copy->next = (*temp);
	return ;
}

void	make_flist(int start, int end, char *line, t_flist **target)
{
	t_flist	*temp;
	int		special;

	temp = malloc_wrap(sizeof(t_flist) * 1);
	temp->next = 0;
	temp->type = 1;
	special = 0;
	if (line[start] == '"' || line[start] == '\'')
	{
		end = skip_quotes(line, start, line[start]);
		start++;
		if (start == end)
		{
			temp->name = ft_strndup("", 1);
			special = 1;
		}
	}
	if (special == 0)
		temp->name = ft_strndup(line + start, (size_t)(end - start));
	ft_flist_add_back(target, &temp);
	return ;
}
