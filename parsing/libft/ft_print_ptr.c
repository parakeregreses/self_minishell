/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:17:19 by jlaine-b          #+#    #+#             */
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

static int	ft_putnbr16(unsigned long int nb)
{
	char	str[16];
	int		i;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	while (nb >= 16)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[i] = base[nb];
	len = i + 1;
	imp_str(str, len);
	return (len + 2);
}

int	ft_print_ptr(void *ptr)
{
	long int	nbr;
	int			i;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	nbr = (unsigned long int) ptr;
	i = ft_putnbr16(nbr);
	return (i);
}
