/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_is_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 05:24:42 by haryu             #+#    #+#             */
/*   Updated: 2022/07/03 22:29:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strndup(char *line, size_t byte)
{
	char	*ret;
	size_t	i;

	ret = malloc_wrap(sizeof(char) * (byte + 1));
	i = 0;
	while (i < byte)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	make_builtin(char ***builtin)
{
	char	*temp;

	temp = BUILTIN;
	(*builtin)[0] = ft_strndup(temp, 4);
	temp += 5;
	(*builtin)[1] = ft_strndup(temp, 2);
	temp += 3;
	(*builtin)[2] = ft_strndup(temp, 3);
	temp += 4;
	(*builtin)[3] = ft_strndup(temp, 6);
	temp += 7;
	(*builtin)[4] = ft_strndup(temp, 5);
	temp += 6;
	(*builtin)[5] = ft_strndup(temp, 3);
	temp += 4;
	(*builtin)[6] = ft_strndup(temp, 4);
	return ;
}

static int	check_builtin(char *target, char *cmd)
{
	int	i;
	int	max_len;
	int	ret;

	i = 0;
	max_len = ft_strlen(target);
	ret = 0;
	while (i < max_len && (cmd[i] || target[i]))
	{
		if (cmd[i] == target[i])
			ret++;
		else
			break ;
		i++;
	}
	if (ret == max_len)
		return (TRUE);
	else
		return (FALSE);
}

int	is_builtin(t_chunk *chunk)
{
	char	**builtin;
	int		i;

	i = 0;
	builtin = malloc_wrap(sizeof(char *) * 8);
	builtin[7] = 0;
	make_builtin(&builtin);
	while (builtin[i])
	{
		if (builtin[i][0] == chunk->argv[0][0] && \
				ft_strlen(builtin[i]) == ft_strlen(chunk->argv[0]))
		{
			if (check_builtin(builtin[i], chunk->argv[0]))
			{
				free_doublestr(&builtin, 7);
				return (TRUE);
			}
		}
		i++;
	}
	free_doublestr(&builtin, 7);
	return (FALSE);
}
