/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:39:45 by haryu             #+#    #+#             */
/*   Updated: 2022/06/18 18:03:56 by cgim             ###   ########.fr       */
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
}				t_global;

extern t_global	g_global;
/* utils */

void	*malloc_wrap(size_t size);

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
void	print_syntex_error(int code);
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

void	print_heredoc_lst(t_flist **target, int height);
void	fork_heredoc(t_flist **heredoc, int height, char *installed);
void	call_cmd(int index, char **cmd, int **pipe);
char	*convert_tilde(char *str);
void	copy_env_val(char *dst, char *str, int i, int cnt);
void	copy_quote(char *dst, char *str, int i, int cnt);
int		count_env_val(char *str, int i);
int		count_quote(char *str, int i);
void	flistadd_back(t_flist **head, t_flist *new);
t_flist	*flistnew(char type, char *name);
char	*get_arg(char *cmd, int i);
char	*get_env(char *str, int i);
char	**init_argv(char *cmd);
int		is_tilde(char *str);
void	print_error_exit(char *err_msg);
int		skip_arg(char *cmd, int i);
int		skip_env(char *str, int i);
int		skip_quote(char *cmd, int i);
int		skip_redirection(char *cmd, int i);
int		skip_whitespace(char *cmd, int i);
t_chunk	*init_structure(int index, char **cmds);
char	**init_argv(char *cmd);

#endif
