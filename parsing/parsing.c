/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/06/19 14:16:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*parsing_minishell(char *str)
{
	t_arg	*arg;

	if (first_verifications(str) == FALSE)
		return (NULL);
	arg = select_quoted_str(str);
	if (arg == NULL)
		return (NULL);
	ft_printf("tab apres selection des quotes \n");
	print_tab_arg(arg);
	arg = separate_pipe(arg);
	return (arg);
}
