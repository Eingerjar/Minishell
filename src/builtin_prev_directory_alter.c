/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_prev_directory_alter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:53:39 by haryu             #+#    #+#             */
/*   Updated: 2022/06/30 13:04:37 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*prev_directory_alter(char *locat)
{
	char	*temp;
	char	*temp2;
	char	*temp3;
	char	*ret;

	temp = prev_directory();
	temp2 = ft_strjoin(temp, "/");
	free(temp);
	temp3 = ft_strdup(locat + 3);
	ret = ft_strjoin(temp2, temp3);
	free(temp2);
	free(temp3);
	return (ret);
}
