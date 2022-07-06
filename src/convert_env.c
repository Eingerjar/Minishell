/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:58:06 by cgim              #+#    #+#             */
/*   Updated: 2022/07/06 10:48:12 by cgim             ###   ########.fr       */
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
		if (str[i] == '$' && str[i + 1] != '\0')
		{
			cnt += count_env_val(str, i);
			i = skip_env(str, i);
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			cnt += skip_quote(str, i) - i;
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
		if (src[i] == '$' && src[i + 1] != '\0')
		{
			copy_env_val(dst, src, i, cnt);
			cnt += count_env_val(src, i);
			i = skip_env(src, i);
		}
		else if (src[i] == '"' || src[i] == '\'')
		{
			ft_memcpy(dst, src + i, skip_quote(src, i) - i);
			cnt += skip_quote(src, i) - i;
			i = skip_quote(src, i);
		}
		else
		{
			dst[cnt++] = src[i];
			i++;
		}
	}
}

char	*convert_env(char *str)
{
	char	*ret;
	int		index;

	index = count_env_val_and_quote(str);
	if (index == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (index + 1));
	if (ret == NULL)
		print_error_exit("convert_env malloc error\n");
	copy_env_val_and_quote(ret, str);
	ret[index] = '\0';
	return (ret);
}
