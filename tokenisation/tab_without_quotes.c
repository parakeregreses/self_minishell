/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_without_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:59:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/10 16:15:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tab_without_quotes(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i] = str_without_quotes(tab[i]);
		i++;
	}
	return (tab);
}
