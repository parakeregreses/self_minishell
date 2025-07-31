#include "minishell.h"

int	main(void)
{
	char	**tokens;

	tokens = malloc(sizeof(char *) * 2);
	tokens[0] = ft_strdup("hello");
	tokens[1] = NULL;

	int	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] != '<')
			i++;
		ft_printf("%s\n", tokens[i]);
	}
}