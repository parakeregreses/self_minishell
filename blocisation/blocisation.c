/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocisation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:16:59 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/13 18:43:36 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*blocisation2(char *str);

// separates the string in different blocs delimitated by the pipes
// such as bloc1 | bloc2 | bloc3
t_arg	*blocisation(char *str)
{
	if (check_closed_quotes(str) == FALSE)
	{
		ft_printf("minishell: syntax problem: unclosed quotes\n");
		return (NULL);
	}
	str = revamp_str(str);
	if (first_verifications(str) == FALSE)
	{
		free(str);
		return (NULL);
	}
	return (blocisation2(str));
}

t_arg	*remove_whitespace_tab(t_arg *arg)
{
	int	i;

	i = 0;
	while ((arg[i]).str != NULL)
	{
		if ((arg[i]).quote == FALSE)
			(arg[i]).str = remove_whitespaces((arg[i]).str);
		i++;
	}
	return (arg);
}

t_arg	*blocisation2(char *str)
{
	t_arg	*arg;

	arg = select_quoted_str(str);
	arg = remove_whitespace_tab(arg);
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
