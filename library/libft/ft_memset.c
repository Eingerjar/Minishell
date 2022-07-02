/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:42:00 by cgim              #+#    #+#             */
/*   Updated: 2022/04/21 10:55:09 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	s;

	p = (unsigned char *)b;
	s = (unsigned char)c;
	while (len > 0)
	{
		*p = s;
		p++;
		len--;
	}
	return (b);
}
