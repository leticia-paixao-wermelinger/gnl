/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:22:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/21 16:30:00 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_line(char *str, int fd, int ret_r)
{
	char		*file;

	file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file)
		return (NULL);
	while (ret_r > 0)
	{
		ret_r = read(fd, file, BUFFER_SIZE);
		if (ret_r <= 0)
		{
			free(file);
			return (NULL);
		}
		file[ret_r] = '\0';
		if (ft_strchr(file, '\n')[0] != '\n')
			str = ft_strjoin(str, file);
		else if (ft_strchr(file, '\n')[0] == '\n'
			|| ft_strchr(file, '\0')[0] == '\0')
		{
			str = ft_strjoin(str, file);
			break ;
		}
	}
	free(file);
	return (str);
}

static char	*cut_line(char *str, char **extra)
{
	char	*temp;

	temp = str;
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n')[0] == '\n')
	{
		*extra = ft_substr(str, my_strchr(str, '\n') + 1, ft_strlen(str));
		str = ft_substr(temp, 0, my_strchr(str, '\n') + 1);
		str[my_strchr(str, '\n') + 1] = '\0';
	}
	free(temp);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
//	free((char *)s);
	return (dest);
}

long unsigned int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*str;

	str = NULL;
	if (!extra)
	{
		str = read_line(str, fd, 1);
		str = cut_line(str, &extra);
		return (str);
	}
	if (!ft_strlen(extra))
	{
		free(extra);
		return (str);
	}
	str = ft_strdup(extra);
	free(extra);
	if (ft_strchr(str, '\n')[0] == '\n')
	{
		str = cut_line(str, &extra);
		return (str);
	}
	str = read_line(str, fd, 1);
	str = cut_line(str, &extra);
	return (str);
}
