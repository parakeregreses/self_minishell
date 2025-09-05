/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_ROK.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:34:37 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:34:39 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_file_rok(char *file1)
{
	char	*message;

	if (access(file1, F_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file1);
		perror(message);
		free(message);
		return (FALSE);
	}
	else if (access(file1, R_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file1);
		perror(message);
		free(message);
		return (FALSE);
	}
	return (TRUE);
}
