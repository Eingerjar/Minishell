/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:36:19 by haryu             #+#    #+#             */
/*   Updated: 2022/06/04 01:55:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * single quotes : -39
 * double quotes : -34
 * both quotes : -183
 * semi collon : -59
 * break point : -44
 * input redirection : -60
 * output redirection : -62
 * heardoc : -120
 * out append : -124
 * parse error : -1
 */

int return_qoutes(int sq, int dq)
{
	int	i;

	i = 0;
	if (sq % 2 != 0 && dq % 2 != 0)
		i = -183;
	else if (sq % 2 != 0 && dq % 2 == 0)
		i = -39;
	else
		i = -34;
	return (i);
}

int	what_is_opposite(char redirect)
{
	if (redirect == 60)
		return (62);
	else
		return (60);
}

void print_syntex_error(int code)
{
	if (code == -39)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -34)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -183)
		printf("😮 syntex error : single & double quotes\n");
	if (code == -59)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -44)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -60)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -62)
		printf("😮 syntex error : %c\n", code * -1);
	if (code == -1)
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
	int	i;
	int	dq;
	int	sq;

	i = index - 1;
	dq = 0;
	sq = 0;
	while(line[++i])
	{
		if (line[i] == 39)
			sq++;
		else if (line[i] == 34)
			dq++;
		if (line[i] == ' ' || line[i] == '|')
			if ((sq % 2 == 0) || (dq % 2 == 0))
				break ;
	}
	if (sq % 2 != 0 || dq % 2 != 0)
		i = return_qoutes(sq, dq);
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
			if ((sq % 2 == 0) || (dq % 2 == 0))
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
	checknum= check_height(line);
	for(int i = 0; i < checknum; i++)
		printf("[%d]%s(%d)\n", i, chunk[i], (int)ft_strlen(chunk[i]));
	chunk_free(chunk, check_height(line));
	return (FALSE);
}

