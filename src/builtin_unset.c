/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:29:21 by cgim              #+#    #+#             */
/*   Updated: 2022/06/29 16:05:44 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(char **argv)
{
	int	i;

	if (argv[1] == NULL)
		return ;
	i = 0;
	while (argv[++i] != NULL)
	{
		ft_del_env(argv[i]);
		ft_del_export(argv[i]);
	}	
}
