/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:12:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 21:44:07 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_verifications(char *str)
{
	if (does_char_end_line(str, '|') == TRUE
		|| is_x_char_in_str(str, '|', 3) == TRUE
		|| does_char_start_line(str, '|') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `|'\n");
		return (FALSE);
	}
	return (TRUE);
}
