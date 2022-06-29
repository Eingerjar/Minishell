/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:18:25 by cgim              #+#    #+#             */
/*   Updated: 2022/06/26 20:23:33 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env()
{
	int	i;

	i = -1;
	while (g_global.wel_env[++i])
	{
		write(1, g_global.wel_env[i], ft_strlen(g_global.wel_env[i]));
		write(1, "\n", 1);
	}
}
