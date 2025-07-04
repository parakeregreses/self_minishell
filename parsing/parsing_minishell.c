/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/07/03 14:05:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*parsing_minishell(char *str)
{
	t_arg	*arg;

	if (first_verifications(str) == FALSE)
		return (NULL);
	arg = select_quoted_str(str);
	ft_printf("quote selected\n");
	print_tab_arg(arg);
	if (arg == NULL)
		return (NULL);
	arg = put_quoted_together(arg);
	// ft_printf("quote reput together\n");
	// print_tab_arg(arg);
	arg = separate_pipe(arg);
	arg = trim_arg(arg);
	return (arg);
}
