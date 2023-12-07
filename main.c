#include "get_next_line.h"
#include <stdio.h>

int	main()
{
//	char	*filename = "/text_test.txt";
	int		fd = open("./text2.txt", O_RDONLY);
	int		i = 1;
	char	*ret;
//	char	*text;

/*	ret = get_next_line(fd);
	printf("teste pós gnl. \nO retorno da GNL foi: %s \n", ret);
	free(ret);*/
	ret = get_next_line(fd);
	while (ret) // na condição, vai entrar uma variável onde eu vou guardar o retorno da GNL enquanto ele não for nulo. E vou mandar imprimir essa variável.
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
}
