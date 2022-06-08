/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:13:36 by haryu             #+#    #+#             */
/*   Updated: 2022/06/08 15:05:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unlink(char *installed)
{
	DIR				*dirptr;
	struct dirent	*file;
	char			*home;
	char			*temp;
	int				i;

	home = ft_strjoin(installed, TEMP);
	dirptr = opendir(home);
	if (!dirptr)
	{
		printf("error 처리가 필요합니다.");
		return(TRUE);
	}
	file = readdir(dirptr);
	i = 0;
	while(file != NULL)
	{
		temp = ft_strjoin(home, file->d_name);
		if (i > 1)
			unlink(temp);
		free(temp);
		file = readdir(dirptr);
		i++;
	}
	closedir(dirptr);
	free(home);
	return (FALSE);
}
