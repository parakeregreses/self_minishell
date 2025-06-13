/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:16:36 by jlaine-b          #+#    #+#             */
/*   Updated: 2024/10/26 15:46:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_atoi(const char *str, int i)
{
	int	j;

	j = i;
	while ('0' <= str[j] && str[j] <= '9')
	{
		j++;
	}
	return (j);
}

static int	ft_pow10(int n)
{
	int	i;
	int	res;

	res = 1;
	i = 1;
	while (i++ <= n)
	{
		res = res * 10;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;
	int	len;

	i = 0;
	res = 0;
	sign = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = i;
		i++;
	}
	len = ft_strlen_atoi(nptr, i);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res + (nptr[i] - '0') * ft_pow10(len - i - 1);
		i++;
	}
	if (nptr[sign] == '-')
		res = -res;
	return (res);
}
