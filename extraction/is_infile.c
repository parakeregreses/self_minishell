/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:46:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:20:22 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_infile(char *file1)
{
	if (access(file1, F_OK | R_OK) != 0)
	{
		perror(ft_strjoin("minishell", file1));
		return (FALSE);
	}
	return (TRUE);
}
