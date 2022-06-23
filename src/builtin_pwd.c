/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:09 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 09:38:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_pwd(char *cmd, char **argv)
{
	char	*current;

	(void)cmd;
	(void)argv;
	current = ft_getcwd();
	printf("%s\n", current);
	free(current);
}
