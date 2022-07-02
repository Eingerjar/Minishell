/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:14:04 by cgim              #+#    #+#             */
/*   Updated: 2021/11/30 11:24:49 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;

	m_dst = (unsigned char *)dst;
	m_src = (unsigned char *)src;
	if (m_dst == 0 && m_src == 0)
		return (0);
	while (n > 0)
	{
		*m_dst = *m_src;
		m_dst++;
		m_src++;
		n--;
	}
	return (dst);
}
