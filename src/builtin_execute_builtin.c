/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execute_builtin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 05:39:04 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 06:39:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_builtin(char **argv)
{
	if (!ft_strncmp("echo", argv[0], ft_strlen("echo")))
		builtin_echo(argv);
	if (!ft_strncmp("cd", argv[0], ft_strlen("cd")))
		builtin_cd(argv);
	if (!ft_strncmp("pwd", argv[0], ft_strlen("pwd")))
		builtin_pwd(argv);
	if (!ft_strncmp("export", argv[0], ft_strlen("export")))
		printf("it is %s\n", argv[0]);
	if (!ft_strncmp("unset", argv[0], ft_strlen("unset")))
		printf("it is %s\n", argv[0]);
	if (!ft_strncmp("env", argv[0], ft_strlen("env")))
		printf("it is %s\n", argv[0]);
	if (!ft_strncmp("exit", argv[0], ft_strlen("exit")))
		ctrld();
	return ;
}
