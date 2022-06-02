/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:20:45 by cgim              #+#    #+#             */
/*   Updated: 2021/11/30 11:32:42 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	unsigned int	size;

	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	size = ft_strlen(src);
	if (n == 0)
		return (size);
	while (n - 1 > 0 && *s_src != '\0')
	{
		*s_dst = *s_src;
		s_dst++;
		s_src++;
		n--;
	}
	*s_dst = '\0';
	return (size);
}
