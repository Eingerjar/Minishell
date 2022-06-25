/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:41:15 by haryu             #+#    #+#             */
/*   Updated: 2022/06/26 08:07:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*make_location(char *locat)
{
	char	*temp;
	char	*temp2;
	char	*ret;

	temp2 = ft_getcwd();
	if (locat[0] == '/')
		return (locat);
	else
	{
		temp = ft_strjoin("/", locat);
		ret = ft_strjoin(temp2, temp);
		free(temp);
	}
	free(temp2);
	return (ret);
}

static char	*prev_directory(void)
{
	char	*temp;
	char	*ret;
	int		i;
	int		prev;

	temp = ft_getcwd();
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '/')
			prev = i;
		if (temp[i] == '/' && temp[i + 1] == 0)
			break ;
		i++;
	}
	if (prev == 0)
	{
		free(temp);
		return (strdup("/"));
	}
	ret = malloc_wrap(sizeof(char) * (prev + 1));
	ret[prev] = 0;
	ft_memmove(ret, temp, prev);
	free(temp);
	return (ret);
}

static char	*check_location(char *locat)
{
	char	*ret;

	ret = NULL;
	if (!locat)
		ret = ft_get_env("HOME");
	else if (locat[0] == '-')
		ret = ft_get_env("OLDPWD");
	else if (locat[0] == '.')
	{
		if (locat[1] == '.')
		{
			ret = prev_directory();
			printf("%s\n", ret);
		}
		else
			ret = ft_getcwd();
	}
	else if (locat[0] == '~')
		ret = ft_strdup(g_global.home);
	else
	{
		ret = make_location(locat);
	}
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

void	builtin_cd(char **argv)
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
	return ;
}
