/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_tab_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:50:21 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 15:53:55 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**trim_tab_free(char **tab, char *set)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i] = ft_strtrimfree(tab[i], set);
		i++;
	}
	return (tab);
}
