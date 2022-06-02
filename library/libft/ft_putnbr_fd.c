/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:48:47 by cgim              #+#    #+#             */
/*   Updated: 2021/11/29 12:09:19 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	l;
	int	digit;

	l = 0;
	digit = 1;
	if (n >= -9 && n <= 9)
		return (1);
	while (n != 0)
	{
		l++;
		n /= 10;
	}
	while (--l != 0)
		digit *= 10;
	return (digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	char	chr;

	digit = count_digit(n);
	if (n < 0)
	{
		chr = '0' - n / digit;
		write(fd, &"-", 1);
		n %= digit;
		n *= -1;
	}
	else
	{
		chr = '0' + n / digit;
		n %= digit;
	}
	write(fd, &chr, 1);
	digit /= 10;
	while (digit != 0)
	{
		chr = '0' + n / digit;
		write(fd, &chr, 1);
		n %= digit;
		digit /= 10;
	}
}
