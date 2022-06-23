/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:39:45 by haryu             #+#    #+#             */
/*   Updated: 2022/06/23 21:45:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LOGIC_H
# define MINI_LOGIC_H

# include "minishell.h"

/*
 * type :
 * 			0 : normal input / normal output
 * 			1 : heredoc input / append mode output
 * name : in&output string
 */
typedef struct s_flist
{
	char			type;
	char			*name;
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
	char	*heredir;
	char	**wel_env;
}				t_global;

extern t_global	g_global;

/* utils */

void	*malloc_wrap(size_t size);
char	**vertical_split(char *line);
void	ft_init_env(void);
void	ft_add_env(char *variable);
void	ft_del_env(char *variable);
char	*ft_get_env(char *variable);
int		length_doublestring(char **str);
void	free_doublestr(char ***target, int size);
int		find_in_env(char *target, char *str);
char	**make_new_double(int omit, int length);
void	print_env(void);

/* main prompt */

char	*current_prompt(void);
char	*ft_getcwd(void);
int		ft_unlink(char *installed);
int		welchs(char *installed);
char	*omitted_dir(char *dir);
char	*make_current_dir(char ***omitted);
char	*omit_longstr(char	*str);
char	*make_current_dir(char ***omitted);
char	*omit_longstr(char	*str);
int		pre_error_check(char *line);
int		check_redirection(char *line, int index, char redirect);
int		check_pipe(char *line, int index);
int		skip_quotes(char *line, int index, char quotes);
int		check_command(char *line, int index);
int		what_is_opposite(char redirect);
int		skip_whitespace_r(int i, char *line);
int		check_whitespace(char *line, int index, char redirect);
int		print_syntex_error(int code);
size_t	check_height(char *line);
void	chunk_free(char **chunk, size_t height);
int		heredoc_check(char *line, char *installed);
t_flist	**pre_heredoc(char **chunks, int height, int *heredocnum);
void	init_flist(t_flist ***target, int height);
void	make_flist(int start, int end, char *line, t_flist **target);
void	make_heredoc(char *line, t_flist **target, int *heredocnum);
int		check_redirection_heredoc(char *line, int index, \
t_flist **target, int *heredocnum);
void	free_heredoc(t_flist **heredoc, int height);
void	free_heredoc_part(t_flist **heredoc);
void	print_chunks(char **chunks, int height);
void	print_heredoc_lst(t_flist **target, int height);
void	fork_heredoc(t_flist **heredoc, int height, char *installed);
void	clean_global(void);
void	handler_heredoc(int signum);
char	*make_filename(int number_cmd, int index_cmd, char *dir);
int		make_temp(char *directory, int *cmdnum);
void	reset_integer_vector(int **vector, int length);
void	check_delimiter(int **cmd, t_flist *delimiter, \
t_flist **heredoc, int maxlen);
void	init_delimiter(int **cmd, t_flist **heredoc);
t_flist	*find_delimiter(int **cmd, t_flist **heredoc);
int		readline_heredoc(int fd, int **cmd, t_flist **heredoc, int height);
void	child_heredoc(t_flist **heredoc, int height, char *installed);
void	putin_to_temp(char *line, int *len, int fd);

/* sentence part */

int		sentence_part(char *line);
int		fork_cmds(int height, char **chunks, int **pipes);
int		ft_wait(pid_t *childs, int numbers);
int		kill_them_all(pid_t *childs, int numbers);
pid_t	*init_pids(int numbers);
int		final_print(int **pipe, int height);
void	close_pipe(int **pipe, int height);
int		**init_pipe(int cmdnum);
void	prepare_pipe(int ***pipes, int height);
void	childs_test(int height, char **chunks, int **pipes);

/* command part */

/* built-in commands */

void	builtin_test(int height, char **chunks, int **pipes);

#endif
