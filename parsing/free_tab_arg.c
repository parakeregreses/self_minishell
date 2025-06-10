#include "minishell.h"

t_arg	*free_tab_arg(t_arg *tab)
{
	int	i;

	i = 0;
	while ((tab[i]).str != NULL)
	{
		ft_printf("i = %d, tab[i] = %s\n", i, (tab[i]).str);
		free((tab[i++]).str);
		ft_printf("i = %d\n", i);
	}
	free(tab);
	return (NULL);
}