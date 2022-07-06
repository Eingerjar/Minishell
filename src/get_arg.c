/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:10:30 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 21:48:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*trim_whitespace(char *str)
{
	int		f_index;
	int		b_index;
	char	*ret;

	f_index = 0;
	b_index = 0;
	while (str[f_index] != '\0' && is_whitespace(str[f_index]))
		f_index++;
	if (str[f_index] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[b_index + 1] != '\0')
		b_index++;
	while (b_index >= 0 && is_whitespace(str[b_index]))
		b_index--;
	ret = (char *)malloc(sizeof(char) * (b_index - f_index + 2));
	if (ret == NULL)
		print_error_exit("trim_whitespace malloc error\n");
	ft_memcpy(ret, str + f_index, b_index - f_index + 1);
	ret[b_index - f_index + 1] = '\0';
	free(str);
	return (ret);
}

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
	ret = trim_whitespace(ret);
	arg = convert_quote(ret);
	free(ret);
	ret = convert_tilde(arg);
	return (ret);
}
