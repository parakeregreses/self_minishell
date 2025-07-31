/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_verifications.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:05:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 16:02:26 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	second_verifications(t_arg *tab)
{
	int	n;

	n = tab_size_arg(tab);
	if (triple_char(tab, n, '<') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `<'");
		return (FALSE);
	}
	if (triple_char(tab, n, '>') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `>'");
		return (FALSE);
	}
	return (TRUE);
}
