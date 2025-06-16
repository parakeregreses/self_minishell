/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:23:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/06/16 17:30:18 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	parse_bloc(char *str)
{
	int		error;
	t_exec	info;

	error = FALSE;
	if (is_x_char_in_str(str, '<', 3) == TRUE)
	{
		ft_printf("bash: syntax error near unexpected token `<'");
		error = TRUE;
	}
	if (is_x_char_in_str(str, '<', 1) == FALSE)
		info.fdin = 0;
	else
		info.fdin = define_fdin(str);
	if (error == TRUE)
	{
		info.cmd = NULL;
		return (info);
	}
	return (info);
}