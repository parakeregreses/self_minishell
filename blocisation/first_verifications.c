/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:12:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/09 15:55:34 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_verifications(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (check_closed_quotes(str) == FALSE)
		return (FALSE);
	if (does_char_end_line(str, '|') == TRUE
		|| is_x_char_in_str(str, '|', 3) == TRUE
		|| does_char_start_line(str, '|') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `|'");
		return (FALSE);
	}
	if (does_char_end_line(str, '<') == TRUE
		|| does_char_start_line(str, '<') == TRUE
		|| does_char_end_line(str, '>') == TRUE
		|| does_char_start_line(str, '>') == TRUE)
		
	{
		ft_printf("minishell: syntax error near unexpected token `newline'");
		return (FALSE);
	}
	if (is_x_char_in_str(str, '<', 3) == TRUE)
		ft_printf("minishell: syntax error near unexpected token `<'");
	if (is_x_char_in_str(str, '>', 3) == TRUE)
		ft_printf("minishell: syntax error near unexpected token `>'");
	return (TRUE);
}
