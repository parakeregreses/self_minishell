/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uphex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:17:55 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 23:49:34 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	imp_str(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &str[len - i - 1], 1);
		i++;
	}
}

int	ft_print_uphex(unsigned int nb)
{
	char	str[16];
	int		i;
	int		len;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	while (nb >= 16)
	{
		str[i++] = base[nb % 16];
		nb = nb / 16;
	}
	str[i] = base[nb];
	len = i + 1;
	imp_str(str, len);
	return (len);
}
