/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_update_vect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:20:38 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 14:57:26 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_strvec(char **strvec, char * variable)
{
	int	i;

	i = -1;
	while (strvec[++i])
	{
		if (find_in_env(strvec[i], variable))
		{
			free(strvec[i]);
			strvec[i] = ft_strdup(variable);
			if (strvec[i] == NULL)
				print_error_exit("ft_update_strvec malloc error\n");
			return ;
		}
	}
}
