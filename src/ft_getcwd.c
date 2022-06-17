/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:12 by haryu             #+#    #+#             */
/*   Updated: 2022/06/17 21:59:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_global	g_global;

char	*ft_getcwd(void)
{
	char	*buf;

	buf = (char *)malloc_wrap(sizeof(char) * BUFFER);
	getcwd(buf, BUFFER);
	return (buf);
}