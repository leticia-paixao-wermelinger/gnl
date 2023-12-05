#include "get_next_line.h"
#include <stdio.h>

int	main()
{
//	char	*filename = "/text_test.txt";
	int		fd = open("./text_test.txt", O_RDONLY);
	int		i = 1;
	char	*ret;

	ret = get_next_line(fd);
	printf("teste pós gnl. \nO retorno da GNL foi: %s \n", ret);
	free(ret);
/*	while (ret) // na condição, vai entrar uma variável onde eu vou guardar o retorno da GNL enquanto ele não for nulo. E vou mandar imprimir essa variável.
	{
		ret = get_next_line(fd);
		printf("Linha %i:\n", i);
		printf("%s\n", ret);
		i++;
		free(ret);
	}*/
}
