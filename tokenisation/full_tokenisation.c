/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_tokenisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:41:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 16:02:43 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***full_tokenisation(t_arg *blocs, int n)
{
	int		i;
	char	***processes;

	i = 0;
	processes = malloc(sizeof(char **) * (n + 1));
	while ((blocs[i]).str != NULL)
	{
		processes[i] = token_bloc((blocs[i]).str);
		i++;
	}
	processes[i] = NULL;
	return (processes);
}
