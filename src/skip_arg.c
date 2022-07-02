/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:10 by cgim              #+#    #+#             */
/*   Updated: 2022/06/24 11:51:20 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_arg(char *cmd, int i)
{
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '<' || cmd[i] == '>' || is_whitespace(cmd[i]))
			break ;
		else if (cmd[i] == '"' || cmd[i] == '\'')
			i = skip_quote(cmd, i);
		else
			i++;
	}
	return (i);
}
