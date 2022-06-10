/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:49:46 by haryu             #+#    #+#             */
/*   Updated: 2022/06/10 20:53:48 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "error.h"
# include "mini_external.h"
# include "mini_logic.h"
# include "parse.h"

# include "../library/libft/libft.h"

# define TRUE 1
# define FALSE 0
# define BUFFER 1024

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define TEMP "/temp/"

# define BUILTIN "echo cd pwd export unset env"

/*
 * type :
 * 			0 : normal input / normal output
 * 			1 : heredoc input / append mode output
 * name : in&output string
 */
typedef struct s_flist
{
	char			type;
	char 			*name;
	struct s_flist	*next;
}				t_flist;

/*
 * argv[0]	: command
 * argv[x]	: arguments
 * input	: redirection input & heredoc
 * output	: redirection output & append mode output
 */
typedef struct s_chunk
{
	char		**argv;
	t_flist		*input;
	t_flist		*output;
}				t_chunk;

typedef struct s_global
{
	int		last_exitcode;
	char	*home; 
}				t_global;

extern int	g_status;

void	copy_env_val(char *dst, char *str, int i, int cnt);
void	copy_quote(char *dst, char *str, int i, int cnt);
int	count_env_val(char *str, int i);
int	count_quote(char *str, int i);
void	flistadd_back(t_flist **head, t_flist *new);
t_flist	*flistnew(char type, char *name);
char	*get_arg(char *cmd, int i);
char	*get_env(char *str, int i);
char	**init_argv(char *cmd);
void	print_error_exit(char *err_msg);
int	skip_arg(char *cmd, int i);
int	skip_env(char *str, int i);
int	skip_quote(char *cmd, int i);
int	skip_redirection(char *cmd, int i);
int	skip_whitespace(char *cmd, int i);
t_chunk	*init_structure(int index, char **cmds);
char	**init_argv(char *cmd);
#endif

