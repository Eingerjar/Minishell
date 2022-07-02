/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:02:09 by cgim              #+#    #+#             */
/*   Updated: 2021/11/28 17:50:10 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int					l;
	unsigned int		tmp;
	char				*p;

	l = count_len(n);
	p = (char *)ft_calloc(l + 1, sizeof(char));
	if (p == 0)
		return (0);
	if (n < 0)
		tmp = n * -1;
	else
		tmp = n;
	while (--l >= 0)
	{
		*(p + l) = 48 + (tmp % 10);
		tmp /= 10;
	}
	if (n < 0)
		*p = '-';
	return (p);
}
