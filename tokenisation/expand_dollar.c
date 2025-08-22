/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:49:39 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 15:34:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**expand_dollar(char **tab, int *ex_code, char **envp)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		// ft_printf("before : tab[i] = %s\n", tab[i]);
		tab[i] = expand_and_unquote(tab[i], *ex_code, envp);
		// ft_printf("after : tab[i] = %s\n", tab[i]);
		i++;
	}
	return (tab);
}
