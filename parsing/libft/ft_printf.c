/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:19:01 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 23:49:34 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print(const char *s, va_list list)
{
	int	i;
	int	sum;
	int	size;

	i = 0;
	sum = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			size = ft_chose_printf(s[i + 1], list);
			if (size == -1)
				return (-1);
			sum = sum + size;
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			sum++;
		}
		i++;
	}
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		sum;
	va_list	list;

	if (ft_parsing_printf(s) == -1)
		return (-1);
	va_start(list, s);
	sum = ft_print(s, list);
	va_end(list);
	return (sum);
}
