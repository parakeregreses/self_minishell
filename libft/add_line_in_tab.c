/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_in_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:29:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/20 18:13:54 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_line_in_tab(char **tab, char *line)
{
	int		n;
	int		i;
	char	**new_tab;

	n = tab_size(tab);
	new_tab = malloc(sizeof(char *) * (n + 2));
	i = 0;
	while (tab[i] != NULL)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i++] = line;
	new_tab[i] = NULL;
	free_tab((void **)tab);
	return (new_tab);
}

// int main(void)
// {
// 	char **tab1;

// 	tab1 = ft_split("hello les amis", ' ');
// 	print_tab_char(tab1);
// 	tab1 = add_line_in_tab(tab1, "Lionel");
// 	print_tab_char(tab1);
// 	free_tab((void **)tab1);
// }