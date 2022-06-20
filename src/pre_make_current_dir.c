/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_make_current_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:11:26 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:11:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

char	*make_current_dir(char ***omitted)
{
	char	*ret;
	char	*temp;
	char	*temp2;
	int		index;

	index = -1;
	ret = ".../";
	while (++index < 3)
	{
		if (ft_strlen((*omitted)[index]) > 10)
			temp = omit_longstr((*omitted)[index]);
		else
			temp = (*omitted)[index];
		temp2 = ft_strjoin(temp, "/");
		free(temp);
		ret = ft_strjoin(ret, temp2);
		free(temp2);
	}
	return (ret);
}
