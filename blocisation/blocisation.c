/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/09 17:12:02 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// separates the string in different blocs delimitated by the pipes
// such as bloc1 | bloc2 | bloc3
t_arg	*blocisation(char *str)
{
	t_arg	*arg;

	str = revamp_str(str);
	if (first_verifications(str) == FALSE)
	{
		free(str);
		return (NULL);
	}
	arg = select_quoted_str(str);
	if (arg == NULL)
		return (NULL);
	if (second_verifications(arg) == FALSE || third_verifications(str) == FALSE)
	{
		free(str);
		free_tab_arg(arg);
		return (NULL);
	}
	arg = put_quoted_together(arg);
	arg = separate_pipe(arg);
	arg = trim_arg(arg);
	arg = delete_empty_lines(arg);
	free(str);
	return (arg);
}
