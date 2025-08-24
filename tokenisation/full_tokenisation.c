/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_tokenisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:41:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 17:58:23 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***full_tokenisation(char **blocs, int n)
{
	int		i;
	char	*set;
	char	***processes;

	set = ft_strdup("<> ");
	i = 0;
	processes = malloc(sizeof(char **) * (n + 1));
	while (blocs[i] != NULL)
	{
		processes[i] = token_bloc(blocs[i], set);
		i++;
	}
	free(set);
	processes[i] = NULL;
	return (processes);
}
