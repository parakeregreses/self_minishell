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

/* print une nouvelle ligne puis dit a readline quon a change de ligne et vider
les inputs pour ensuite remontrer la ligne de texte vide avec minishell$ */
static void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_finished = 1;
		wait(NULL);
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

/*POUR MAC*/
//static void	signal_handler(int signal)
//{
//	if (signal == SIGINT)
//	{
//		printf("\n");
//		rl_on_new_line();
//#ifdef __APPLE__
//		rl_set_prompt("");
//		rl_redisplay();
//		rl_set_prompt("minishell$ ");
//#else
//		rl_replace_line("", 0);
//		rl_redisplay();
//#endif
//	}
//	else if (signal == SIGQUIT)
//	{
//		rl_on_new_line();
//		rl_redisplay();
//	}
//}

void	get_signal(void)
{
	struct sigaction	handler;

	handler.sa_handler = signal_handler;
	sigemptyset(&handler.sa_mask);
	handler.sa_flags = 0;
	sigaction(SIGINT, &handler, NULL);
	signal(SIGQUIT, SIG_IGN);
}
