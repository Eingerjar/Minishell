/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_init_tcsetattr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:14:16 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 12:03:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_tcsetattr(struct termios *new)
{
	tcgetattr(0, &g_global.old_settings);
	(*new) = g_global.old_settings;
	new->c_lflag |= ICANON;
	new->c_cc[VQUIT] = 255;
	tcsetattr(0, TCSANOW, new);
	main_signal();
	return ;
}
