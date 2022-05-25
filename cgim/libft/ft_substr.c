/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:25:15 by cgim              #+#    #+#             */
/*   Updated: 2021/12/01 14:23:29 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == 0)
		return (0);
	p = (char *)malloc(len + 1);
	if (p == 0)
		return (0);
	ft_bzero(p, len + 1);
	if (start >= ft_strlen(s))
		return (p);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
