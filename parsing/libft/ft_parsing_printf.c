/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:15:26 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 23:52:10 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parsing_printf(const char *s)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && !ft_charinstr("cspdiuxX%\0", s[i + 1]))
		{
			if (s[i] == '%' && s[i - 1] != '%' )
				return (-1);
		}
		i++;
	}
	return (0);
}
