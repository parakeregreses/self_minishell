/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:16:11 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/01/16 23:52:14 by jlaineb          ###   ########.fr       */
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

static int	ft_intmin(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_print_int(int nb)
{
	char	str[10];
	int		i;
	int		len;
	int		res;

	i = 0;
	res = 0;
	if (nb == -2147483648)
		return (ft_intmin());
	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
		res = 1;
	}
	while (nb > 9)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = nb + '0';
	len = i + 1;
	imp_str(str, len);
	return (res + len);
}
