/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:26:14 by cgim              #+#    #+#             */
/*   Updated: 2021/11/24 14:13:06 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char			*p;
	unsigned int	l;

	l = ft_strlen(s1);
	p = (char *)malloc(l + 1);
	if (p == 0)
		return (0);
	return ((char *)ft_memcpy(p, s1, l + 1));
}
