/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:58:44 by cgim              #+#    #+#             */
/*   Updated: 2021/12/03 11:27:17 by cgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_split(char const *s, char c)
{
	unsigned int	len;
	char			tmp;

	len = 0;
	tmp = c;
	while (*s != '\0')
	{
		if (tmp == c && *s != c)
		{
			tmp = *s;
			len++;
		}
		else if (tmp != c && *s == c)
			tmp = c;
		s++;
	}
	return (len);
}

static unsigned int	clen(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static void	free_array(char **pp)
{
	unsigned int	i;

	i = 0;
	while (pp[i])
	{
		free(pp[i]);
		i++;
	}
	free(pp);
}

static char	**alloc_str(char **pp, char const *s, char c, unsigned int count)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (*s != '\0' && i < count)
	{
		while (*s == c)
			s++;
		len = clen(s, c);
		pp[i] = (char *)ft_calloc(len + 1, sizeof(char));
		if (pp[i] == 0)
		{
			free_array(pp);
			return (0);
		}
		ft_strlcpy(pp[i++], s, len + 1);
		s = s + len;
	}
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	char			**pp;
	unsigned int	count;

	if (s == 0)
		return (0);
	count = count_split(s, c);
	pp = (char **)ft_calloc(count + 1, sizeof(char *));
	if (pp == 0)
		return (0);
	pp = alloc_str(pp, s, c, count);
	return (pp);
}
