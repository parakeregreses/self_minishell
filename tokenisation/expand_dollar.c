/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:49:39 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 17:10:36 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**expand_dollar(char **tab, int *status, char **envp)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i] = expand_and_unquote(tab[i], *status, envp);
		i++;
	}
	return (tab);
}
