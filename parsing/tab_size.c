/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:36 by jlaineb           #+#    #+#             */
/*   Updated: 2025/05/22 20:17:01 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_size(char **tab)
{
	int	len;

	len = 0;
	if (tab == NULL)
		return (len);
	while (tab[len] != NULL)
		len++;
	return (len);
}
