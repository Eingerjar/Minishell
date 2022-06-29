/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_update_vect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:20:38 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 20:25:54 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_strvec(char **strvec, char *variable)
{
	int	i;
	int	size;

	i = -1;
	size = count_equal_offset(variable);
	while (strvec[++i])
	{
		if (ft_strncmp(strvec[i], variable, size) == 0 && variable[size] == '=')
		{
			printf("%s ", strvec[i]);
			free(strvec[i]);
			strvec[i] = ft_strdup(variable);
			if (strvec[i] == NULL)
				print_error_exit("ft_update_strvec malloc error\n");
			printf("-> %s\n", strvec[i]);
			return ;
		}
	}
}
