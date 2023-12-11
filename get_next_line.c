/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:22:18 by lpaixao-          #+#    #+#             */
/*   Updated: 2023/12/11 19:41:02 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
			return (NULL);
		file[ret_r] = '\0';
		printf("Conteúdo de file logo após o red: %s \n", file);
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
		printf("Teste final do while da read_line: %s\n", str);
		free(file);
	}
	printf("Teste dentro da read_line pós loop: %s\n", str);
	return (str);
}

static char	*cut_line(char *str, char *extra)
{
	printf("entrou na cut_line com str = %s\nEntrou na cut_line com extra = %s\n", str, extra);
	if (ft_strchr(str, '\n')[0] == '\n')
	{
		extra = ft_substr(str, my_strchr(str, '\n'), ft_strlen(str));
		str = ft_substr(str, 0, my_strchr(str, '\n'));
		printf("retorno de strchr com uma quebra de linha %s\n", extra);
	}
/*	else if (ft_strchr(str, '\0')[0] == '\0')
	{
		//extra = ft_strchr(str, '\0');
		return (str);
	}*/
	return (str);
}

static char	*check_extra(char *extra) // Função em construção
{
	/*
		A função precisa:
			1- Ver se tem outro /n
			2- Se tiver um /n, vai retornar todo o conteúdo até ele e não vai poder entrar nas
			outras funções depois, pq é exatamente isso q a GNL vai retornar
			3- Se não tiver, só vai salvar o resto do conteúdo na str e vai seguir para o read_line
	*/
	char	*str;

	if (ft_strchr(extra, '\n')[0] == '\n')
	{
		str = ft_substr(extra, 0, my_strchr(extra, '\n'));
		extra = ft_substr(extra, my_strchr(str, '\n'), ft_strlen(str));
	}
	if ()
	return (str);
}

char    *get_next_line(int fd)
{
	static char	*extra;
	char		*str;

	str = NULL;
	if (!extra)
		extra = NULL;
	
	str = read_line(str, fd);
	str = cut_line(str, extra);
//	save_extra();
	return (str);
}
