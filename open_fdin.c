/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:43:57 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 15:58:59 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_fdin(t_fdin info)
{
	int	fdin;

	if (info.fdin == 0 && info.here_doc == 1)
		fdin = open(info.tempfile.filename, O_RDONLY);
	else if (info.fdin == 0)
		return (0);
	else
		fdin = open(info.filename, O_RDONLY);
	return (fdin);
}
