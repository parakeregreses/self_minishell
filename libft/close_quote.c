/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:41:41 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 13:46:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if str[i] == c, find the next occurence of c in str and returns its position
int	close_quote(char *str, int i, char c)
{
	i++;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == 0)
		return (-1);
	i++;
	return (i);
}
