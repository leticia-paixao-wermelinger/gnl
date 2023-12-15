/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:22:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/14 18:46:23 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(char *str, int fd)
{
	char		*file;
	int			ret_r;

	ret_r = 1;
	while (ret_r > 0)
	{
		file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ret_r = read(fd, file, BUFFER_SIZE); // foguete não dá ré
		if (ret_r <= 0)
		{
			free(file);
			return (NULL);
		}
		file[ret_r] = '\0';
		if (ft_strchr(file, '\n')[0] != '\n')
			str = ft_strjoin(str, file);
		else if (ft_strchr(file, '\n')[0] == '\n' || ft_strchr(file, '\0')[0] == '\0')
		{
			str = ft_strjoin(str, file);
			free(file);
			break ;
		}
		free(file);
	}
	return (str);
}

static char	*cut_line(char *str, char **extra)
{
	char	*temp;

	temp = NULL;
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n')[0] == '\n')
	{
		*extra = ft_substr(str, my_strchr(str, '\n'), ft_strlen(str));
		temp = ft_substr(str, 0, my_strchr(str, '\n'));
/*		if (str) // Com esse free comentado, o código funciona mas (obviamente) dá leak. Com
 *		esse free, o código dá free(): invalid pointer e Aborted (core dumped).
			free(str);*/
		str = temp;
	}
	return (str);
}

static char	*ft_strdup(const char *s)
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
	return (dest);
}

char    *get_next_line(int fd)
{
	static char	*extra;
	char		*str;

	str = NULL;
	if (!extra)
		extra = NULL;
	if (extra)
	{
		str = ft_strdup(extra);
		free(extra);
		extra = NULL;
		if (str[0] == '\n')
			str = &str[1];
		if (ft_strchr(str, '\n')[0] == '\n')
		{
			str = cut_line(str, &extra); 
			return (str);
		}
		str = read_line(str, fd);
		str = cut_line(str, &extra);
	}
	else
	{
		str = read_line(str, fd);
		str = cut_line(str, &extra);
	}
	return (str);
}
