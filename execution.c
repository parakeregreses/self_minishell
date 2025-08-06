/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/06 13:23:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:52:25 by jlaineb           #+#    #+#             */
/*   Updated: 2025/04/15 17:41:01 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_cmd(t_fds fds, t_arg arg, char **cmd_paths, int i)
// close le pipe[OUT] dans lequel on va ecrire au prealable !!!

void	perror_free_and_exit_child(char **tab, int exit_status, char *message)
{
	free_tab((void *)tab);
	perror(message);
	exit(exit_status);
}

void	execution(t_exec info, int piperead[2], int pipewrite[2], char **envp, int i)
{
	pid_t	pid;
	int		fdin;

	fdin = find_fdin(info.infile, piperead, i);
	// ft_printf("i = %d, fdin = %d, fdout = %d\n", i, fdin, info.fdout);
	// ft_printf("pipe1[READ] = %d, pipe1[WRITE] = %d, pipe2[READ] = %d, pipe2[WRITE] = %d\n", piperead[READ], piperead[WRITE], pipewrite[READ], pipewrite[WRITE]);
	pid = fork();
	if (pid == 0)
	{
		if (info.cmdpath == NULL)
			perror_free_and_exit_child(info.cmdarg, EXIT_SUCCESS, "cmdissue");
		if (dup2(fdin, 0) == -1 || dup2(info.fdout, 1) == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "close1");
		close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, envp);
		perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "exec");
	}
	wait(NULL);
	// if (close(info.fdout) == -1 || close(fdin) == -1)
	// 	perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "close2");
	// int	n;
	// char c;
	// n = read(pipewrite[READ], &c, 1);
	// while (n == 1)
	// {
	// 	// ft_printf("a_n = %d", n, c);
	// 	write(1, &c, 1);
	// 	n = read(pipewrite[READ], &c, 1);
	// }
	// ft_printf("\nn = %d\n", n);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char	**cmdarg;
// 	int		fdin;
// 	char	*chemin;

// 	cmdarg = malloc(sizeof(char *) * 3);
// 	cmdarg[0] = ft_strdup("grep");
// 	cmdarg[1] = ft_strdup("a");
// 	cmdarg[2] = NULL;
// 	fdin = open("text.txt", O_RDWR);
// 	chemin = ft_strdup("/usr/bin/grep");
// 	if (argc == -1 || argv == NULL)
// 		return (0);
// 	execution(fdin, 1, cmdarg, envp);
// 	close(fdin);
// 	free(chemin);
// 	free_tab((void *)cmdarg);
// }
