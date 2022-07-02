/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_make_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:09:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/02 10:54:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*make_filename(int number_cmd, int index_cmd, char *dir)
{
	char	*temp1;
	char	*temp2;
	char	*numbers;

	temp1 = ft_strjoin(dir, TEMPFILE);
	numbers = ft_itoa(number_cmd);
	temp2 = ft_strjoin(temp1, numbers);
	free(numbers);
	free(temp1);
	temp1 = ft_strjoin(temp2, "_");
	free(temp2);
	numbers = ft_itoa(index_cmd);
	temp2 = ft_strjoin(temp1, numbers);
	free(numbers);
	free(temp1);
	return (temp2);
}
