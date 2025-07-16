#include "minishell.h"

void	test(char *line, char c)
{
	int	i;
	// int	j = 0;
	
	i = 0;
	while (line[i] && ft_strchri(line + i, c) != -1)
	{
		line = line + i;
		printf("i = %d, %s, %d\n", i, line, ft_strchri(line, c));
		i = ft_strchri(line, c);
		i++;
	}
}

int	main(void)
{
	test("hello les amis", ' ');
}