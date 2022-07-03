/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tcsetattr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:14:16 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 08:02:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_tcsetattr(struct termios *new)
{
	(*new) = g_global.old_settings;
	new->c_lflag |= ICANON;
	new->c_cc[VQUIT] = 255;
	tcsetattr(0, TCSANOW, new);
	main_signal();
	return ;
}

void	back_tcsetattr(struct termios *old)
{
	(*old) = g_global.old_settings;
	old->c_cc[VQUIT] = 28;
	tcsetattr(0, TCSANOW, old);
	return ;
}
