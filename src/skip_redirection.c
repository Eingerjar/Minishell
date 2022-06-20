/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:30:29 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 11:30:29 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_redirection(char *cmd, int i)
{
	i++;
	if (cmd[i] == '<' || cmd[i] == '>')
		i++;
	if (cmd[i] == ' ')
		i = skip_whitespace(cmd, i);
	i = skip_arg(cmd, i);
	return (i);
}
