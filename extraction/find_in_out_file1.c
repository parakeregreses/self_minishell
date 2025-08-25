/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_out_file1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:50:44 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/25 15:52:13 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	find_in_out_file2(char **t, t_utils u, int i, t_exec info);

t_exec	find_in_out_file(char **t, int *status, char ***envp, t_exec info)
{
	t_utils	u;
	int		i;

	u.envp = envp;
	u.status = status;
	i = 0;
	return (find_in_out_file2(t, u, i, info));
}
