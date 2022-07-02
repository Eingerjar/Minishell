/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_current_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:48:21 by haryu             #+#    #+#             */
/*   Updated: 2022/06/27 01:54:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*current_prompt(void)
{
	char	*ret;
	char	*front;
	char	*last;
	char	*middle;

	front = "\033[0;35m🥤 shell \033[0;36m\"";
	last = "\" \033[0;37m \n>> ";
	middle = ft_getcwd();
	ret = omitted_dir(middle);
	free(middle);
	middle = ft_strdup(ret);
	free(ret);
	ret = ft_strjoin(CYAN, middle);
	free(middle);
	middle = ft_strjoin(front, ret);
	free(ret);
	ret = ft_strjoin(middle, last);
	free(middle);
	return (ret);
}
