/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:49:39 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 21:20:59 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**expand_dollar(char **tab, int *status, char **envp)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i] = dollar_signs(tab[i], *status, envp);
		// printf("tab[i] = %s\n", tab[i]);
		i++;
	}
	return (tab);
}
