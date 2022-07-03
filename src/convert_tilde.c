/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:38:58 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 10:39:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_tilde(char *str)
{
	char	*ret;
	int		size;

	if (str[0] == '~' && (str[1] == '/' || str[1] == '\0'))
	{
		size = ft_strlen(g_global.home) + ft_strlen(str + 1) + 1;
		ret = (char *)malloc(size);
		if (ret == NULL)
			print_error_exit("convet_tilde malloc error\n");
		ret[0] = '\0';
		ft_strlcat(ret, g_global.home, size);
		ft_strlcat(ret, str + 1, size);
		free(str);
		return (ret);
	}
	return (str);
}
