/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:53:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/05 13:24:16 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// helper functions

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	size_src;

	count = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size > 0)
	{
		while (src[count] && count < (size - 1))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (size_src);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*st;

	i = 0;
	ch = (char)c;
	st = (char *)s;
	while (st[i] != '\n' && st[i])
	{
		if (st[i] == ch)
			return (&st[i]);
		i++;
	}
	if (c == '\n')
		return ("0");
	if (c == '\0')
		return (&st[i]);
	return (NULL);
}

long unsigned int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	free(s1);
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc((len * sizeof(char)) + 1);
	if (!substr || !s)
		return (NULL);
	while (len > 0)
	{
		if (start >= ft_strlen(s))
			substr[i++] = '\0';
		else
			substr[i++] = s[start++];
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
