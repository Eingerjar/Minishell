/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:03:30 by cgim              #+#    #+#             */
/*   Updated: 2022/04/21 10:54:24 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	mc;

	p = (unsigned char *)s;
	mc = (unsigned char)c;
	while (n > 0)
	{
		if (*p == mc)
			return ((void *)p);
		p++;
		n--;
	}
	return (0);
}
