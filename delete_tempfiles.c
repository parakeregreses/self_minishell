/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tempfiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:47:48 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/06 11:18:40 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tempfiles(t_exec *infos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((infos[i]).infile.here_doc == 1)
		{
			unlink((infos[i]).infile.tempfilename);
			free((infos[i]).infile.tempfilename);
		}
		i++;
	}
}
