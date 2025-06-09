#include "minishell.h"

void	print_tab_arg(t_arg *text)
{
	int	i;

	i = 0;
	while ((text[i]).str != NULL)
	{
		ft_printf("%d | %s\n", (text[i]).quote, (text[i]).str);
		i++;
	}
}