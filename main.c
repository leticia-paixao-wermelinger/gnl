#include "get_next_line.h"
#include <stdio.h>

int	main()
{
//	char	*filename = "/text_test.txt";
//	int		fd = open("./text2.txt", O_RDONLY);
	int		fd = open("./text_test.txt", O_RDONLY);
	int		i = 1;
	char	*ret;
//	char	*text;

/*	ret = get_next_line(fd);
	printf("teste pós gnl. \nO retorno da GNL foi: %s \n", ret);
	free(ret);*/
	if (fd <= 0)
	{
		printf("open retornou erro com fd: %i \n", fd);
		return (1);
	}
	ret = get_next_line(fd);
	while (ret)
	{
		printf("Linha %i:\n", i);
		printf("%s\n", ret);
		if (ret)
		{
			free(ret);
			ret = NULL;
		}
		ret = get_next_line(fd);
		i++;
		if (i > 10)
			break ;
	}
//	free(ret);
	if (fd >= 3)
		close(fd);
}
