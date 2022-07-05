/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:19:57 by haryu             #+#    #+#             */
/*   Updated: 2022/07/05 21:20:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(char *path, char *cmd)
{
	char	*ret;
	int		size;

	size = ft_strlen(path) + ft_strlen(cmd) + 2;
	ret = (char *)malloc(sizeof(char) * size);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, path, size);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, cmd, size);
	return (ret);
}
