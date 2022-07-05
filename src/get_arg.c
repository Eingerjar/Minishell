/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:10:30 by cgim              #+#    #+#             */
/*   Updated: 2022/07/05 22:25:59 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg(char *cmd, int i)
{
	char	*arg;
	char	*ret;
	int		index;

	index = skip_arg(cmd, i) - i;
	arg = (char *)malloc(sizeof(char) * (index + 1));
	if (arg == NULL)
		print_error_exit("get_arg malloc error\n");
	ft_memcpy(arg, cmd + i, index);
	arg[index] = '\0';
	ret = convert_env(arg);
	free(arg);
	if (ret == NULL)
		return (NULL);
	arg = convert_quote(ret);
	free(ret);
	ret = convert_tilde(arg);
	if (ret != arg)
		free(arg);
	return (ret);
}
