/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:05:45 by cgim              #+#    #+#             */
/*   Updated: 2022/06/18 17:12:50 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_tilde(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '~')
	{
		if (str[1] == '\0')
			return (1);
		else if (str[1] == '/')
			return (1);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
