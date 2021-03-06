/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:09:34 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 11:04:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	make_temp(char *directory, int *cmdnum)
{
	char	*tempfile;
	int		ret;

	tempfile = make_filename(cmdnum[0], cmdnum[1], directory);
	ret = open(tempfile, O_CREAT | O_RDWR | O_APPEND, S_IRUSR);
	if (ret < 0)
	{
		free(tempfile);
		printf("%sOPEN ERROR, %s", RED, strerror(errno));
		exit(1);
	}
	free(tempfile);
	return (ret);
}
