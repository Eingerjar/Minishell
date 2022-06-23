/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 03:43:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*check_location(char *locat)
{
	char	*ret;

	if (!locat)
		ret = ft_get_env("HOME");
	else if (locat[0] == '-')
		ret = ft_get_env("OLDPWD");
	else if (locat[0] == '.')
	{
		if (locat[1] = '.')
			printf("still under working\n");
		else
			printf("still under working\n");
	}
	else
		ret = ft_strdup(locat);
	return (ret);
}

static void	dir_env_add(char *pwd, char *oldpwd)
{
	char	*temp;

	ft_del_env("PWD");
	temp = ft_strjoin("PWD=", pwd);
	ft_add_env(temp);
	free(temp);
	ft_del_env("OLDPWD");
	temp = ft_strjoin("OLDPWD=", oldpwd);
	ft_add_env(temp);
	free(temp);
}

static int	check_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	builtin_cd(char *cmd, char **argv)
{
	char	*location;
	char	*oldpwd;
	int		error;

	oldpwd = ft_getcwd();
	location = check_location(argv[1]);
	error = chdir(location);
	if (error == -1)
	{
		printf("😭 no such file or directory: %s\n", location);
		g_global.last_exitcode = 1;
		return ;
	}
	dir_env_add(location, oldpwd);
	free(oldpwd);
	free(location);
	free_doublestr(&argv, check_argc);
	return ;
}
