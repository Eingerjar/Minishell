/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:47:16 by cgim              #+#    #+#             */
/*   Updated: 2022/03/17 15:15:11 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_overflow(long long *result, long long tmp, int sign)
{
	if (*result < tmp)
	{
		if (sign == 1)
			*result = -1;
		else
			*result = 0;
		return (1);
	}
	return (0);
}

static	int	ft_isspace(char chr)
{
	if (chr == '\t' || chr == '\n' || chr == '\v'
		|| chr == '\f' || chr == '\r' || chr == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int			sign;
	long long	result;
	long long	tmp;

	sign = 1;
	result = 0;
	tmp = 0;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		tmp = result;
		result *= 10;
		result += (*str - 48);
		str++;
		if (check_overflow(&result, tmp, sign))
			break ;
	}
	return (sign * result);
}
