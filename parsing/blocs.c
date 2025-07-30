/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/30 18:04:54 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*blocs(char *str)
{
	t_arg	*arg;

	if (first_verifications(str) == FALSE)
		return (NULL);
	arg = select_quoted_str(str);
	if (arg == NULL)
		return (NULL);
	if (second_verifications(arg) == FALSE)
	{
		free_tab_arg(arg);
		return (NULL);
	}
	arg = put_quoted_together(arg);
	arg = separate_pipe(arg);
	arg = trim_arg(arg);
	arg = delete_empty_lines(arg);
	return (arg);
}
