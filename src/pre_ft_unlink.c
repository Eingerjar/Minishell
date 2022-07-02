/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_ft_unlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:13:36 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 13:18:34 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	delete_all(struct dirent *file, DIR *dirptr, char *home)
{
	char	*temp;
	int		i;

	i = 0;
	while (file != NULL)
	{
		temp = ft_strjoin(home, file->d_name);
		if (i > 1)
			unlink(temp);
		free(temp);
		file = readdir(dirptr);
		i++;
	}
}

int	ft_unlink(char *installed)
{
	DIR				*dirptr;
	struct dirent	*file;
	char			*home;

	home = ft_strjoin(installed, TEMP);
	dirptr = opendir(home);
	if (!dirptr)
	{
		printf("There is no temp forlder.\n");
		return (TRUE);
	}
	file = readdir(dirptr);
	delete_all(file, dirptr, home);
	closedir(dirptr);
	free(home);
	return (FALSE);
}
