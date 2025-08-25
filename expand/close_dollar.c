/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:39:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 22:42:47 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_dollar(char *str, int i)
{
	if (str[i] && ft_isnum(str[i]))
	{
		while (str[i] && ft_isnum(str[i]))
			i++;
	}
	else
	{
		while (str[i] && !ft_ischarinset(str[i], "\'\" $"))
			i++;
	}
	return (i);
}
