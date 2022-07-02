/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:39:33 by cgim              #+#    #+#             */
/*   Updated: 2021/11/30 11:32:04 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t	s)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;
	size_t			dstsize;
	size_t			srcsize;

	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (s == 0 || dstsize >= s)
		return (srcsize + s);
	while (s > dstsize + 1 && *s_src != '\0')
	{
		*(s_dst + dstsize) = *s_src;
		s_dst++;
		s_src++;
		s--;
	}
	*(s_dst + dstsize) = '\0';
	return (dstsize + srcsize);
}
