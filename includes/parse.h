/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:58:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/08 16:49:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis		: split command line for making chunks.
 *
 * @Param line		: whole command line for making chunks.
 *
 * @Returns   		: chunks or NULL
 */
/* ----------------------------------------------------------------------------*/
char	**vertical_split(char *line);

#endif

