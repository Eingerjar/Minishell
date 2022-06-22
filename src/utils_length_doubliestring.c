/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_length_doubliestring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:25:44 by haryu             #+#    #+#             */
/*   Updated: 2022/06/22 21:26:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	length_doublestring(char **str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}
