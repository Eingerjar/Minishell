/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:39:16 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 11:39:17 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_env(char *str, int i)
{
	i++;
	if (str[i] == '?' || ft_isdigit(str[i]))
		return (i + 1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == '_')
			i++;
		else
			break ;
	}
	return (i);
}
