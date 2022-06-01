/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <cgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:51:45 by cgim              #+#    #+#             */
/*   Updated: 2021/12/01 14:28:57 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	unsigned int	i;
	char			*p;

	if (s == 0)
		return (0);
	l = ft_strlen(s);
	p = (char *)malloc((l + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (i < l)
	{
		*(p + i) = f(i, *(s + i));
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
