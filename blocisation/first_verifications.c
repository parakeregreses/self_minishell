/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:12:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/10 15:00:55 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_verifications(char *str)
{
	if (does_char_end_line(str, '|') == TRUE
		|| is_x_char_in_str(str, '|', 3) == TRUE
		|| does_char_start_line(str, '|') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `|'");
		return (FALSE);
	}
	return (TRUE);
}
