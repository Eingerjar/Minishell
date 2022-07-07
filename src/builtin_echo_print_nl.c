/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_print_nl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:34:52 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 17:40:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_echo_flags(int *flag, int *first, int *other)
{
	if (*flag == 1)
		*first = 1;
	else
		*first = 0;
	*flag = 0;
	*other = 0;
	return ;
}

int	echo_print_nl(int flag)
{
	if (flag == FALSE)
	{
		write(1, "\n", 1);
		return (TRUE);
	}
	else
		return (TRUE);
}
