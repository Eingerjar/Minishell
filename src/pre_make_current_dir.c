/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_make_current_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:11:26 by haryu             #+#    #+#             */
/*   Updated: 2022/07/01 20:08:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*make_current_dir(char ***omitted)
{
	char	*ret;
	char	*temp;
	char	*temp2;
	char	*temp3;
	int		index;

	index = -1;
	ret = ".../";
	while (++index < 3)
	{
		if (ft_strlen((*omitted)[index]) > 10)
			temp = omit_longstr((*omitted)[index]);
		else
			temp = ft_strdup((*omitted)[index]);
		temp2 = ft_strjoin(temp, "/");
		free(temp);
		temp3 = ft_strdup(ret);
		if (index != 0)
			free(ret);
		ret = ft_strjoin(temp3, temp2);
		free(temp2);
		free(temp3);
	}
	return (ret);
}
