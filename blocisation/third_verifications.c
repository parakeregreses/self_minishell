/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:07:21 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/09 17:09:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	third_verifications(char *str)
{
	if (does_char_end_line(str, '<') == TRUE 
		|| does_char_end_line(str, '>') == TRUE)
	{
		ft_printf("minishell: syntax error near unexpected token `newline'");
		return (FALSE);
	}
	return (TRUE);
}
