/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 23:18:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int return_qoutes(int sq, int dq)
{
	int	i;

	i = 0;
	if (sq % 2 != 0 && dq % 2 != 0)
		i = BQ;
	else if (sq % 2 != 0 && dq % 2 == 0)
		i = SQ;
	else
		i = DQ;
	return (i);
}

int	what_is_opposite(char redirect)
{
	if (redirect == IR)
		return (OR);
	else
		return (IR);
}

void print_syntex_error(int code)
{
	if (code == SQ)
		printf("😮 syntex error : %c\n", SQ * -1);
	if (code == DQ)
		printf("😮 syntex error : %c\n", DQ * -1);
	if (code == BQ)
		printf("😮 syntex error : single & double quotes\n");
	if (code == SEMI)
		printf("😮 syntex error : %c\n", SEMI * -1);
	if (code == COM)
		printf("😮 syntex error : %c\n", COM * -1);
	if (code == IR)
		printf("😮 syntex error : %c\n",IR * -1);
	if (code == OR)
		printf("😮 syntex error : %c\n", OR * -1);
	if (code == PARSE)
		printf("😮 parse error near \\n\n");

}

int	check_redirection(char *line, int index, char redirect)
{
	int	i;
	int	opposite;

	i = index;
	opposite = what_is_opposite(redirect);
	if (line[index + 1] == ' ')
		i++;
	if (line[index + 1] == opposite)
		return (opposite * -1);
	if (i + 2 > (int)ft_strlen(line))
		return (-1);
	if (line[index + 2] == ' ' && line[index + 3] == ' ')
		i = -1;
	return (i);
}

int	check_quotes(char *line, int index)
{
	int		i;
	int		quotes;
	char	quotes_checker;

	quotes = 0;
	quotes_checker = line[index];
	i = index - 1;
	while(line[++i])
	{
		if (line[i] == quotes_checker)
			quotes++;
		if (line[i] == ' ' || line[i] == '|')
			if (quotes % 2 == 0)
				break ;
	}
	if (quotes % 2 != 0)
		i = quotes_checker * -1;
	if (i > 0 && i == (int)ft_strlen(line) && \
			(line[i - 1] == ';' || line[i - 1] == ',' ))
		return (line[i - 1] * -1);
	return (i);
}

int	check_command(char *line, int index)
{
	int	i;
	int	dq;
	int	sq;

	i = index;
	dq = 0;
	sq = 0;
	if (line[i] == '|')
		if (line[i + 1] == '|')
			return (-1);
	while(line[++i])
	{
		if (line[i] == 39)
			sq++;
		else if (line[i] == 34)
			dq++;
		if (line[i] == ' ' || line[i] == '|')
			if ((sq % 2 == 0) && (dq % 2 == 0))
				break ;
	}
	if (sq % 2 != 0 || dq % 2 != 0)
		i = return_qoutes(sq, dq);
	if (i > 0 && i == (int)ft_strlen(line) && \
			(line[i - 1] == ';' || line[i - 1] == ',' ))
		return (line[i - 1] * -1);
	return (i);
}

int	check_line(char *line)
{
	int error;
	int	i;

	i = -1;
	error = FALSE;
	while(line[++i])
	{
		if (line[i] == 39 || line[i] == 34)
			i = check_quotes(line, i);
		else if (line[i] == 60 || line[i] == 62)
			i = check_redirection(line, i, line[i]);
		else if (line[i] == 49 || line[i] == 59)
			i = line[i] * -1;
		else
			i = check_command(line, i);
		if (i < 0)
		{
			print_syntex_error(i);
			error = TRUE;
			break ;
		}
		if (i >= (int)ft_strlen(line))
			break ;
	}
	return (error);
}

int pre_error_check(char *line)
{
	char	**chunk;
	int		checknum;

	if (check_line(line))
		return (TRUE);
	chunk = vertical_split(line);
	checknum = check_height(line);
	for(int i = 0; i < checknum; i++)
		printf("[%d]%s(%d)\n", i, chunk[i], (int)ft_strlen(chunk[i]));
	chunk_free(chunk, check_height(line));
	return (FALSE);
}

