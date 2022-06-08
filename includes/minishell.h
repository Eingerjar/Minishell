/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:49:46 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 23:25:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/resource.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include "./readline/readline.h"
# include "./readline/history.h"
# include <termios.h>
# include <termcap.h>
# include <term.h>

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

/* error macro */
/* Single quotes */
# define SQ -39
/* Double quotes */
# define DQ -34
/* Both quotes */
# define BQ -183
/* Semi colon */
# define SEMI -59
/* Comma */
# define COM -44
/* Input redirection */
# define IR -60
/* Output redirection */
# define OR -62
/* Heredoc redirection */
# define HD -120
/* Output Append mode */
# define OAP -124
/* PARSE */
# define PARSE -1

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

/* initialize temp directory into empty. */
int		ft_unlink(char *current);
/* check current directory */
char	*ft_getcwd(void);

/* error check */
/* error check 1st */
int		pre_error_check(char *line);
/*
 *
 * */

/* utils */
/* main frontend */
int		welchs(void);
/* smart split */
char 	**vertical_split(char *line);
size_t	check_height(char *line);
/* chunk free */
void	chunk_free(char **chunk, size_t height);
/* main */
int sentence_part(char **chunk, int pipenum, char *installed);

#endif
