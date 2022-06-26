/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pro_or_not.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:16:37 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 17:17:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int builtin_pro_or_not(char **chunks)
{
	if (!ft_strncmp(chunks[0], "echo", 4))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "pwd", 3))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "env", 3))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "export", 6) && !chunks[1])
		return (TRUE);
	return (FALSE);
}
