/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pro_or_not.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:16:37 by haryu             #+#    #+#             */
/*   Updated: 2022/06/29 18:13:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_pro_or_not(char **chunks)
{
	if (!ft_strncmp(chunks[0], "echo", 4))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "pwd", 3))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "env", 3))
		return (TRUE);
	if (!ft_strncmp(chunks[0], "export", 6) && \
			ft_strlen(chunks[0]) == 6 && !chunks[1])
		return (TRUE);
	if (!ft_strncmp(chunks[0], "export", 6) && \
			chunks[1] && chunks[1][0] != '\0')
		return (FALSE);
	return (FALSE);
}
