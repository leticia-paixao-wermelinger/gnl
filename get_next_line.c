/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:22:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/19 19:06:04 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static char	*read_line(char *str, int fd)
{
	char		*file;
//	char		*temp;
	int			ret_r;

	ret_r = 1;
	file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file)
		return (NULL);
	while (ret_r > 0)
	{
		ret_r = read(fd, file, BUFFER_SIZE); // foguete não dá ré
		if (ret_r <= 0)
		{
			free(file);
			return (NULL);
		}
		file[ret_r] = '\0';
		if (ft_strchr(file, '\n')[0] != '\n')
		{
//			temp = str;
			str = ft_strjoin(str, file);
//			free(temp);
		}
		else if (ft_strchr(file, '\n')[0] == '\n' || ft_strchr(file, '\0')[0] == '\0')
		{
//			temp = str;
			str = ft_strjoin(str, file);
//			free(temp);
			break ;
		}
	}
	free(file);
	return (str);
}

static char	*cut_line(char *str, char **extra)
{
	char	*temp;

	//printf("----------------:%s:\n", str);
	temp = str;
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n')[0] == '\n')
	{
		*extra = ft_substr(str, my_strchr(str, '\n') + 1, ft_strlen(str));
		str = ft_substr(temp, 0, my_strchr(str, '\n') + 1);
		str[my_strchr(str, '\n') + 1] = '\0';
		//if (str) // Com esse free comentado, o código funciona mas (obviamente) dá leak. Com		esse free, o código dá free(): invalid pointer e Aborted (core dumped).
		//	free(str);
//		str = temp;
		//if (temp)
		//	free(temp);
	}
	free(temp);
	//printf("----------->:%s:\n", str);
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
	//char		*temp;
	char		*str;

	str = NULL;
	if (!extra)
		extra = NULL;
	if (extra)
	{
		str = ft_strdup(extra);
		free(extra);
		extra = NULL;
		if (ft_strchr(str, '\n')[0] == '\n')
		{
			//temp = str;
			str = cut_line(str, &extra);
			//free(temp);
			return (str);
		}
		//temp = str;
		str = read_line(str, fd);
		//temp = str;
		str = cut_line(str, &extra);
		//free(temp);
	}
	else
	{
		//temp = str;
		str = read_line(str, fd);
		//free(temp);
		//temp = str;
		str = cut_line(str, &extra);
		//free(temp);
	}
	return (str);
}
