/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:47:58 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 19:47:59 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_quote(char *dst, char *str, int i, int cnt)
{
	int	q;

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
			copy_env_val(dst, str, i, cnt);
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else
		{
			dst[cnt] = str[i];
			cnt++;
		}
		i++;
	}
}
