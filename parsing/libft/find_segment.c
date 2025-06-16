/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 08:23:54 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/09 22:28:18 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// find the segment delimited by the two first occurence of char c in str,
// and returns their pointers
t_segment	find_segment(char *str, char c)
{
	t_segment	s;
	int			i;

	i = 0;
	while (str[i] != 0 && str[i] != c)
		i++;
	if (str[i] == 0)
	{
		s.start = 0;
		s.end = 0;
		return (s);
	}
	s.start = i++;
	while (str[i] != 0 && str[i] != c)
		i++;
	s.end = i;
	return (s);
}
