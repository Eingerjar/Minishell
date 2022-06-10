/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:50:16 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 13:50:18 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote(char *str, int i)
{
	int	cnt;
	int	q;

	cnt = 0;
	if (str[i] == '"')
		q = 2;
	else
		q = 1;
	i++;
	while (q != 0)
	{
		if ((str[i] == '"' && q == 2) || (str[i] == '\'' && q == 1))
			q = 0;
		else if (str[i] == '$' && q == 2)
		{
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else
			cnt++;
		i++;
	}
	return (cnt);
}
