/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_print_syntex_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:22:42 by haryu             #+#    #+#             */
/*   Updated: 2022/06/19 22:05:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_syntex_error(int code)
{
	if (code == SQ)
		printf("😮 syntex error : %c\n", SQ * -1);
	else if (code == DQ)
		printf("😮 syntex error : %c\n", DQ * -1);
	else if (code == SEMI)
		printf("😮 syntex error near unexpected token : %c\n", SEMI * -1);
	else if (code == COM)
		printf("😮 syntex error near unexpected token  : %c\n", COM * -1);
	else if (code == IR)
		printf("😮 syntex error near unexpected token  : %c\n", IR * -1);
	else if (code == OR)
		printf("😮 syntex error near unexpected token  : %c\n", OR * -1);
	else if (code == PARSE)
		printf("😮 parse error near unexpected token :\\n\n");
	else if (code == -124)
		printf("😮 syntex error near unexpected token  : %c\n", code * -1);
	else if (code == -38)
		printf("😅 This is a bonus opperand\n");
	else
		printf("😮 syntex error near unexpected token : %c\n", code * -1);
}
