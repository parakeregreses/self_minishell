/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:20:57 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 20:22:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipes	initpipes(void)
{
	t_pipes	p;

	p.pipe2[0] = -1;
	p.pipe2[1] = -1;
	return (p);
}

t_2d	initstd(void)
{
	t_2d	std;

	std.in = dup(0);
	std.out = dup(1);
	return (std);
}

t_utils	initutils(t_exec *infos, int n, char ***envp, int *status)
{
	t_utils	u;

	u.infos = infos;
	u.n = n;
	u.envp = envp;
	u.status = status;
	u.i = 0;
	return (u);
}
