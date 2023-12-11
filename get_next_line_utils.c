/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:53:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/11 19:19:53 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// helper functions
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
		return (&st[i]);
	if (c == '\0')
		return (&st[i]);
	return (NULL);
}

int	my_strchr(const char *s, int c)
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
			return i;
		i++;
	}
/*	if (c == '\n')
		return i;
	if (c == '\0')
		return i;*/
	return i;
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
	if (!s2)
		return (NULL);
	if (!s1)
	{
		 s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
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
