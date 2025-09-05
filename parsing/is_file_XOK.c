/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_XOK.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:27:15 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 12:37:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_file_XOK(char *file1, int *status)
{
	char	*message;

	if (access(file1, F_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file1);
		perror(message);
		free(message);
		*status = 127;
		return (FALSE);
	}
	else if (access(file1, X_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file1);
		perror(message);
		free(message);
		*status = 126;
		return (FALSE);
	}
	return (TRUE);
}
