/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_ft_getcwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:44:12 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:32:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getcwd(void)
{
	char	*buf;

	buf = (char *)malloc_wrap(sizeof(char) * BUFFER);
	getcwd(buf, BUFFER);
	return (buf);
}
