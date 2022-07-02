/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:20:14 by cgim              #+#    #+#             */
/*   Updated: 2022/06/10 11:20:19 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_exit(char *err_msg)
{
	int	size;

	size = ft_strlen(err_msg);
	write(2, err_msg, size);
	exit(1);
}
