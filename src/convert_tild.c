/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:14:17 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 18:11:43 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_tilde(char *str)
{
	int		size;
	char	*ret;

	if (str == NULL)
		print_error_exit("conver_tilde NULL error\n");
	size = ft_strlen(g_global.home) + ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * size);
	if (ret == NULL)
		print_error_exit("convet_tilde malloc error\n");
	ret[0] = '\0';
	ft_strlcat(ret, g_global.home, size);
	ft_strlcat(ret, str + 1, size);
	free(str);
	return (ret);
}
