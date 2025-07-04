/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:21:07 by jlaine-b          #+#    #+#             */
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

int	ft_print_udec(unsigned int nb)
{
	char	str[10];
	int		i;
	int		len;

	i = 0;
	while (nb > 9)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = nb + '0';
	len = i + 1;
	imp_str(str, len);
	return (len);
}
