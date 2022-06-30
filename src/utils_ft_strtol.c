/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_strtol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:28 by haryu             #+#    #+#             */
/*   Updated: 2022/06/30 17:03:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_overflow(long long value, char *str, int sign)
{
	if (ft_strlen(str) > 2)
		return (TRUE);
	if (value > ELMAX)
		return (TRUE);
	else if (value == ELMAX)
	{
		if (sign == 1)
		{
			if (str[1] <= '7')
				return (FALSE);
			else
				return (TRUE);
		}
		else if (sign == -1)
		{
			if (str[1] < '8')
				return (FALSE);
			else
				return (TRUE);
		}
	}
	return (FALSE);
}

static int	check_minus(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_strtol(long long *dest, char *str)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str && is_whitespace(*str))
		str++;
	sign = check_minus(&str);
	i = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		i++;
		result *= 10;
		result += (*str - 48);
		if (i == 18 && check_overflow(result, str, sign))
			return (TRUE);
		str++;
	}
	*dest = sign * result;
	return (FALSE);
}
