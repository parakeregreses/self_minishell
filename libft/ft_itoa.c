/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:03:41 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/24 10:55:16 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_str(char *str, int len, int n)
{
	int		i;
	char	*stra;

	stra = malloc(sizeof(char) * (len + 1));
	if (!stra)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		stra[i] = '-';
		i++;
	}
	while (i < len)
	{
		stra[i] = str[len - i - 1];
		i++;
	}
	stra[i] = '\0';
	return (stra);
}

static char	*ft_itoamin(char *stra)
{
	stra = malloc(sizeof(char) * 12);
	if (!stra)
		return (NULL);
	ft_strlcpy(stra, "-2147483648", 12);
	return (stra);
}

static char	*ft_itoanmin(int n, char *stra)
{
	char	str[10];
	int		i;
	int		len;
	int		nb;

	i = 0;
	len = 0;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = nb + '0';
	len = len + i + 1;
	stra = ft_alloc_str(str, len, n);
	return (stra);
}

char	*ft_itoa(int n)
{
	char	*stra;

	stra = NULL;
	if (n == -2147483648)
		stra = ft_itoamin(stra);
	else
		stra = ft_itoanmin(n, stra);
	return (stra);
}
