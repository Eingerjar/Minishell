/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:43:47 by cgim              #+#    #+#             */
/*   Updated: 2021/12/01 14:25:31 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*p;
	char const	*start;
	char const	*end;

	if (s1 == 0 || set == 0)
		return (0);
	start = s1;
	end = s1 + ft_strlen(s1);
	if (start == end)
	{
		p = (char *)malloc(1);
		if (p == 0)
			return (0);
		*p = '\0';
		return (p);
	}
	while (*start && ft_strchr(set, *start))
		start++;
	while (*(end - 1) && ft_strchr(set, *(end - 1)) && start < end - 1)
		end--;
	p = (char *)malloc(end - start + 1);
	if (p == 0)
		return (0);
	ft_strlcpy(p, start, end - start + 1);
	return (p);
}
