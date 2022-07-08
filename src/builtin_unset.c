/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:29:21 by cgim              #+#    #+#             */
/*   Updated: 2022/07/08 11:42:47 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_unset(char *str)
{
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (0);
	str++;
	while (*str != '\0')
	{
		if (ft_isalnum(*str) || *str == '_')
			str++;
		else
			return (0);
	}
	return (1);
}

void	builtin_unset(char **argv)
{
	int	i;

	if (argv[1] == NULL)
		return ;
	i = 0;
	while (argv[++i] != NULL)
	{
		if (is_unset(argv[i]))
		{
			ft_del_env(argv[i]);
			ft_del_export(argv[i]);
		}
		else
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
		}
	}	
}
