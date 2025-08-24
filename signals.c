/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   signals.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/19 15:41:37 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/20 18:28:34 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

bool	g_finished = 0;

static void	signal_handler(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_finished = 1;
}

void	get_signal(void)
{
	struct sigaction	handler;

	handler.sa_handler = signal_handler;
	sigemptyset(&handler.sa_mask);
	handler.sa_flags = SA_RESTART;
	sigaction(SIGINT, &handler, NULL);
	signal(SIGQUIT, SIG_IGN);
}
