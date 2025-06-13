/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chose_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:14:58 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 23:48:54 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chose_printf(char s, va_list liste)
{
	if (s == 'c')
		return (ft_print_char(va_arg(liste, int)));
	if (s == 's')
		return (ft_print_str(va_arg(liste, char *)));
	if (s == 'p')
		return (ft_print_ptr(va_arg(liste, void *)));
	if (s == 'i' || s == 'd')
		return (ft_print_int(va_arg(liste, int)));
	if (s == 'u')
		return (ft_print_udec(va_arg(liste, unsigned int)));
	if (s == 'x')
		return (ft_print_lowhex(va_arg(liste, unsigned int)));
	if (s == 'X')
		return (ft_print_uphex(va_arg(liste, unsigned int)));
	if (s == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}
