/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_putin_to_temp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:38 by haryu             #+#    #+#             */
/*   Updated: 2022/07/06 16:31:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	putin_to_temp_env(char *putin, int *i, int fd)
{
	char	*env;
	char	*temp;

	env = get_env(putin, *i);
	temp = ft_get_env(env);
	(*i) = skip_env(putin, *i) - 1;
	if (temp)
		write(fd, temp, ft_strlen(temp));
	free(env);
	free(temp);
}

void	putin_to_temp(char *line, int *len, int fd)
{
	char	*putin;
	int		i;

	putin = NULL;
	putin = ft_strjoin(line, "\n");
	*len += ft_strlen(putin);
	i = 0;
	while (putin[i])
	{
		if (putin[i] != '$')
			write(fd, &putin[i], 1);
		else if (putin[i] == '$')
		{
			if (!ft_isalnum(putin[i + 1]))
			{
				write(fd, &putin[i], 1);
			}
			else
				putin_to_temp_env(putin, &i, fd);
		}
		i++;
	}
	free(putin);
}
