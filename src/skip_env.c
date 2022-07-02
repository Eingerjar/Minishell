/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:39:16 by cgim              #+#    #+#             */
/*   Updated: 2022/07/01 21:19:29 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_env(char *str, int i)
{
	i++;
	if (str[i] == '?')
		return (i + 1);
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
		return (i);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == '_')
			i++;
		else
			break ;
	}
	return (i);
}
