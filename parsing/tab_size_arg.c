/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:36 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 16:19:21 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_size_arg(t_arg *tab)
{
	int	len;

	len = 0;
	if (tab == NULL)
		return (len);
	while ((tab[len]).str != NULL)
		len++;
	return (len);
}
