/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only1ac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:29:36 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/24 13:04:45 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	i;

	srcsize = 0;
	i = 0;
	if (!src || !dest)
		return (0);
	srcsize = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = malloc(size);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, size);
	return (dup);
}

static size_t	ft_countword(char const *s, char c, t_stuff *stuff)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	stuff->ssize = count;
	return (count);
}

size_t	wlensplit(char const *s, char c )
{
	size_t wlen;

	wlen = 0;
	if (!ft_strchr(s, c))
		wlen = ft_strlen(s);
	else
		wlen = ft_strchr(s, c) - s;
	return (wlen);
}

char	**ft_split(char const *s, char c, t_stuff *stuff)
{
	int		i;
	char	**lst2;
	size_t	wlen;

	if (!s || !stuff)
		return (NULL);
	lst2 = (char **)malloc((ft_countword(s, c, stuff) + 1) * sizeof(char *));
	if (!s || !lst2)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			wlen = wlensplit(s, c);
			lst2[i] = ft_substr(s, 0, wlen);
			s += wlen;
			i++;
		}
	}
	lst2[i] = NULL;
	return (lst2);
}
