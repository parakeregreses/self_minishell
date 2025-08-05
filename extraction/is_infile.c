/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:46:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 13:06:26 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_infile(char *file1)
{
	char	*message;

	if (access(file1, F_OK | R_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file1);
		perror(message);
		free(message);
		return (FALSE);
	}
	return (TRUE);
}
