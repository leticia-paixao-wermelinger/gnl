/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:37 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/05 17:24:25 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
//	static char	*extra;
	char		*str;
	char		*file;
	int			ret_r;
//	char		*ret_join;
	int			i;

	i = 0;
	ret_r = 1;
	str = NULL;
	while (ret_r > 0)
	{
		file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ret_r = read(fd, file, BUFFER_SIZE); // foguete não dá ré
		if (!ret_r)
			return (NULL);
		file[BUFFER_SIZE] = '\0';
		i = i + 1;
		printf("Passagem %i pelo while() da GNL. \nConteúdo de file: %s \n", i, file);
		if ((ft_strchr(file, '\n')[0] != '\n' && ft_strchr(file, '\0')[0] != '\0') && (!str))
		{
			str = ft_substr(file, 0, BUFFER_SIZE);
			printf("str pós substr: %s\n", str);
		}
		else if ((ft_strchr(file, '\n')[0] != '\n' && ft_strchr(file, '\0')[0] != '\0') && str)
		{
			str = ft_strjoin(str, file);
			printf("passou o join\n");
			//ft_strlcpy(str, ret_join, (ft_strlen(ret_join)));
			//printf("passou o lcpy\n");
			//free(ret_join);
		}
		else if (ft_strchr(file, '\n')[0] == '\n' || ft_strchr(file, '\0')[0] == '\0')
		{
			free(file);
			printf("olá, João!");
			break ;
		}
/*		if (file[i] == '\n')
		{
			i++;
			ie = 0;
			while (file[i] != '\0')
				extra[ie++] = file[i++];
		}*/
		printf("Teste dentro da GNL: %s\n", str);
		free(file);
	}
	printf("Teste dentro da GNL pós loop: %s\n", str);
	return (str);
}
