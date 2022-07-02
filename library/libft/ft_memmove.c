/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:25:15 by cgim              #+#    #+#             */
/*   Updated: 2021/11/30 11:25:26 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;

	m_dst = (unsigned char *)dst;
	m_src = (unsigned char *)src;
	if (m_dst == 0 && m_src == 0)
		return (0);
	while (len > 0)
	{
		if (m_dst > m_src)
			*(m_dst + len - 1) = *(m_src + len - 1);
		else
		{
			*m_dst = *m_src;
			m_dst++;
			m_src++;
		}
		len--;
	}
	return (dst);
}
