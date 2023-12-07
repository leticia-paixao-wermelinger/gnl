/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:37 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/07 19:10:03 by lpaixao-         ###   ########.fr       */
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
	int			i;

	i = 0;
	ret_r = 1;
	str = NULL;
	while (ret_r > 0)
	{
		file = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ret_r = read(fd, file, BUFFER_SIZE); // foguete não dá ré
		if (ret_r <= 0)
			return (NULL);
		file[ret_r] = '\0';
		i = i + 1;
		printf("Passagem %i pelo while() da GNL. \nConteúdo de file: %s \n", i, file);
		if (ft_strchr(file, '\n')[0] != '\n')
		{
			str = ft_strjoin(str, file);
			printf("passou o join\n");
		}
		else if (ft_strchr(file, '\n')[0] == '\n' || ft_strchr(file, '\0')[0] == '\0')
		{
			printf("no terceiro if\n");
			printf("pré join str: %s | file: %s\n", str, file);
			str = ft_strjoin(str, file);
			free(file);
			printf("pós join str: %s | file: %s\n", str, file);
			break ;
		}
		printf("Teste dentro da GNL: %s\n", str);
		free(file);
	}
	printf("Teste dentro da GNL pós loop: %s\n", str);
	return (str);
}
