/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:10:30 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 19:28:55 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_env_val_and_quote(char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			cnt += count_quote(str, i);
			i = skip_quote(str, i);
		}
		else
		{
			i++;
			cnt++;
		}
	}
	return (cnt);
}

static void	copy_env_val_and_quote(char *dst, char *src)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '$')
		{
			copy_env_val(dst, src, i, cnt);
			cnt += count_env_val(src, i);
			i = skip_env(src, i);
		}
		else if (src[i] == '"' || src[i] == '\'')
		{
			copy_quote(dst, src, i, cnt);
			cnt += count_quote(src, i);
			i = skip_quote(src, i);
		}
		else
		{
			dst[cnt++] = src[i];
			i++;
		}
	}
}

static char	*convert_env_and_quote(char	*str)
{
	char	*ret;
	int		index;

	index = count_env_val_and_quote(str);
	ret = (char *)malloc(sizeof(char) * (index + 1));
	if (ret == NULL)
		return (NULL);
	copy_env_val_and_quote(ret, str);
	ret[index] = '\0';
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
	ret = convert_env_and_quote(arg);
	return (ret);
}
