/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:20:36 by haryu             #+#    #+#             */
/*   Updated: 2022/07/05 21:20:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_execute(char **argv, char **argv_copy, char *path)
{
	char	*tmp;

	tmp = get_cmd(path, argv_copy[0]);
	free(argv[0]);
	argv[0] = tmp;
	execve(argv[0], argv, g_global.wel_env);
}
