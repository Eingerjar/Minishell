/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_clean_global.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:04:08 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 12:07:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/mini_logic.h"

extern t_global	g_global;

void	clean_global(void)
{
	g_global.last_exitcode = 0;
	return ;
}
