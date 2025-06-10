#include "minishell.h"

t_arg	*free_tab_arg(t_arg *tab)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
		free((tab[i++]).str);
	free(tab);
	return (NULL);
}