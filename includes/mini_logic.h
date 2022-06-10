/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:39:45 by haryu             #+#    #+#             */
/*   Updated: 2022/06/10 23:11:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LOGIC_H
# define MINI_LOGIC_H

# include "./minishell.h"

/* main prompt */

/*
 * @Synopsis "current_prompt"
 *
 * @Returns : get current path and make prompt lines
 */
char	*current_prompt(void);
/**
 * @Synopsis "ft_getcwd"
 *
 * @Returns : get current path.
 */
char	*ft_getcwd(void);
/**
 * @Synopsis  "ft_unlink"
 *
 * @Param installed : the directory which minishell is installed on.
 *
 * @Returns         : if it delete all temp file, return 0 and if it can't return -1.
 */

int		ft_unlink(char *installed);

/**
 * @Synopsis  "welchs"
 *
 * @Returns   success to expose image of a welchs return 0.
 */
int		welchs(void);

/**
 * @Synopsis	"pre_error_check"
 *
 * @Param line : whole commands line for parsing.
 *
 * @Returns    : if this function finish check error, make return 0 for make chunks of commands. if not, return 1.
 */
int		pre_error_check(char *line);

int		check_redirection(char *line, int index, char redirect);

int		check_pipe(char *line, int index);

int		skip_quotes(char *line, int index, char quotes);

int		check_command(char *line, int index);

void	print_syntex_error(int code);

/**
 * @Synopsis	"check_height"
 *
 * @Param line : whole commands line for parsing.
 *
 * @Returns    : check how many pipe in there.(size_t)
 */
size_t	check_height(char *line);

/**
 * @Synopsis  		: free all chunk(utility)
 *
 * @Param chunk		: commands that are taken apart.
 * @Param height	: the number of commands.
 */
void	chunk_free(char **chunk, size_t height);

int		heredoc_check(char *line);

void	print_chunks(char **chunks, int height);

/* sentence part */

/* command part */

#endif
