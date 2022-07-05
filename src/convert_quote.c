/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:16:41 by cgim              #+#    #+#             */
/*   Updated: 2022/07/05 21:31:29 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_str_and_quote(char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
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

static void	copy_str_and_quote(char *dst, char *src)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '"' || src[i] == '\'')
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

char	*convert_quote(char *str)
{
	char	*ret;
	int	index;

	index = count_str_and_quote(str);
	ret = (char *)malloc(sizeof(char) * (index + 1));
	if (ret == NULL)
		print_error_exit("convert_quote malloc error\n");
	copy_str_and_quote(ret, str);
	ret[index] = '\0';
	return (ret);
}
