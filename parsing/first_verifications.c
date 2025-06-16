/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:12:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 12:22:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_verifications(char *str)
{
	if (str[0] == '|' || is_x_char_in_str(str, '|', 3) == TRUE
		|| str[ft_strlen(str) - 1] == '|')
	{
		ft_printf("minishell: syntax error near unexpected token `|'");
		return (FALSE);
	}
	return (TRUE);
}
