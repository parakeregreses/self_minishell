/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:14:36 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/06 14:11:28 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
