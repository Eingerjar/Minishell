/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:09:01 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*make_filename(int number_cmd, int index_cmd, char *dir)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(dir, TEMPFILE);
	temp2 = ft_strjoin(temp1, ft_itoa(number_cmd));
	free(temp1);
	temp1 = ft_strjoin(temp2, "_");
	free(temp2);
	temp2 = ft_strjoin(temp1, ft_itoa(index_cmd));
	free(temp1);
	return (temp2);
}
