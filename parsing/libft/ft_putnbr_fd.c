/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:16:01 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/25 18:32:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	imp_str(char *str, int len, int fd)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(fd, &str[len - i - 1], 1);
		i++;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	str[10];
	int		i;
	int		len;

	i = 0;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write (fd, "-", 1);
		}
		while (nb > 9)
		{
			str[i] = (nb % 10) + '0';
			nb = nb / 10;
			i++;
		}
		str[i] = nb + '0';
		len = i + 1;
		imp_str(str, len, fd);
	}
}
