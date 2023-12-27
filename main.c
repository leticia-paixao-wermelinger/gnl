#include "get_next_line.h"

#include <stdio.h>

int	my_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	main()
{
//	char	*filename = "/text_test.txt";
	int		fd = open("./text2.txt", O_RDONLY);
//	int		fd = open("./text_test.txt", O_RDONLY);
//	int     fd = open("./41_no_nl", O_RDONLY);
	int		i = 1;
	char	*ret;
//	char	*text;

	if (fd <= 0)
	{
		printf("open retornou erro com fd: %i \n", fd);
		return (1);
	}
	ret = get_next_line(fd);
	while (ret)
	{
		printf("Linha %i:\n", i);
		my_putstr(ret);
		if (ret)
		{
			free(ret);
			ret = NULL;
		}
		ret = get_next_line(fd);
		i++;
		if (i > 100)
			break ;
	}
	free(ret);
	if (fd >= 3)
		close(fd);
}
