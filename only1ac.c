/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only1ac.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:29:36 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/22 17:15:19 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

/*char	**ft_split(char const *s, char c, t_stuff *stuff)
{
	char	**lst;
    char    **tmp;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
    stuff->ssize = i;
    return (tmp);
}*/
char **ft_split(char const *s, char c, t_stuff *stuff) {
    char **lst;
    size_t word_len;
    int i = 0;

    if (!s || !stuff)
        return NULL;  // Early return if `s` or `stuff` is NULL

    // Allocate memory for the list of strings
    lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
    if (!lst)
        return NULL;  // Memory allocation failed

    while (*s) {
        // Skip delimiters
        while (*s == c && *s)
            s++;

        // If we found a word
        if (*s) {
            // Determine word length
            if (!ft_strchr(s, c))
                word_len = ft_strlen(s);  // Word goes till the end
            else
                word_len = ft_strchr(s, c) - s;  // Find next delimiter

            // Allocate memory for the word and copy it
            lst[i] = ft_substr(s, 0, word_len);
            if (!lst[i]) {
                // Free previously allocated memory on error
                while (i-- > 0)
                    free(lst[i]);
                free(lst);
                return NULL;  // Memory allocation failure
            }

            i++;
            s += word_len;  // Move the pointer forward
        }
    }

    lst[i] = NULL;  // Null-terminate the list
    stuff->ssize = i;  // Store the number of words

    return lst;
}
// Function to free the memory allocated by `ft_split`
void ft_free_split(char **lst) {
    if (!lst) return;

    // Free each string in the array
    for (int i = 0; lst[i]; i++) {
        free(lst[i]);
    }

    // Free the array itself
    free(lst);
}

void newav(char **av, t_stuff *stuff)
{
    char **tmp;
    
    tmp = ft_split(av[1], ' ', stuff);
    stuff->lst = tmp;
    ft_free_split(tmp);
}
