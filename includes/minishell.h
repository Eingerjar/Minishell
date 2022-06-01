/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:49:46 by haryu             #+#    #+#             */
/*   Updated: 2022/06/01 19:20:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>

# define BUILTIN "echo cd pwd export unset env"

/*
 * type :
 * 			0 : normal input / normal output
 * 			1 : heredoc input / append mode output
 * name : in&output string
 */
typedef struct s_queue
{
	char	type;
	char 	*name;
	t_queue	*next;
}t_queue;

typedef struct s_chunk
{
	char		**argv;
	t_queue		*input;
	t_queue		*output;
}t_chunk;

#endif
