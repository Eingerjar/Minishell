/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_putin_to_temp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:08:38 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 02:31:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	putin_to_temp(char *line, int *len, int fd)
{
	char	*putin;

	putin = NULL;
	putin = ft_strjoin(line, "\n");
	*len += ft_strlen(putin);
	write(fd, putin, ft_strlen(putin));
	free(putin);
}
