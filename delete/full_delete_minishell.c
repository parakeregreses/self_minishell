/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_delete_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:44:56 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 15:20:12 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	full_delete_minishell(t_exec *infos, int n)
{
	int	i;

	i = 0;
	delete_tempfiles(infos, n);
	while (i != n)
	{
		free_tab((void **)(infos[i]).cmdarg);
		free((infos[i]).cmdpath);
		free((infos[i]).infile.filename);
		free((infos[i]).outfile.filename);
		i++;
	}
	free(infos);
	return (0);
}
