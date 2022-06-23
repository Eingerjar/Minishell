/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_series.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:51:57 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:34:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_chunks(char **chunks, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		printf("[%d] %s(%d)\n", i, chunks[i], (int)ft_strlen(chunks[i]));
		i++;
	}
}

void	print_heredoc_lst(t_flist **target, int height)
{
	int		i;
	t_flist	*temp;

	i = 0;
	while (i < height)
	{
		temp = target[i]->next;
		printf("%d 번 커멘드 heredoc\n", i);
		while (temp != 0)
		{
			printf("%s\n", temp->name);
			temp = temp->next;
		}
		i++;
	}
	return ;
}
