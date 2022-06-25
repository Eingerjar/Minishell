/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 06:40:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_echo(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1] == 0)
			return ;
		write(1, " ", 1);
	}
}
