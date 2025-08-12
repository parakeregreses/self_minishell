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

#include "../includes/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

/* print une nouvelle ligne puis dit a readline quon a change de ligne et vider
les inputs pour ensuite remontrer la ligne de texte vide avec minishell$ */
static void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
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

int	empty_argument(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

// int	mini_parsing(char *line, char **tab, char **envp, int i)
// {
// 	int		status;
// 	pid_t	pid;

// 	if (ft_strncmp(line + i, "cd", 2) == 0)
// 	{
// 		tab = ft_split(line, ' ');
// 		cmd_cd((const char **) tab, envp);
// 		return (0);
// 	}
// 	if (ft_strcmp(line + i, "ls") == 0)
// 	{
// 		pid = fork();
// 		tab = ft_split(line, ' ');
// 		if (pid == 0)
// 		{
// 			execve("/usr/bin/ls", tab, envp);
// 			exit(1);
// 		}
// 		else
// 			waitpid(pid, &status, 0);
// 		return (0);
// 	}
// 	return (1);
// }

int	launching(char **envp)
{
	char	*line;
	int		found;
	char	*prompt;
	int		i;

	get_signal();
	while (1)
	{
		i = 0;
		prompt = cat_current_dir();
		line = readline(prompt);
		free(prompt);
		found = 1;
		if (!line)
		{
			ft_printf("exit\n");
			break ;
		}
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (ft_strncmp(line + i, "exit", 4) == 0)
		{
			free(line);
			ft_printf("exit\n");
			break ;
		}
		else
			judith(line, envp);
		if (line[0] != '\0' && !empty_argument(line))
			add_history(line);
		free (line);
	}
	return (0);
}

/* ------------------- */

//int	main(int argc, char **argv, char **envp)
//{
//	pid_t	pid;
//	char	*line;
//	char	**tab;
//	int		found;
//	int		status;

//	(void)argc;
//	(void)argv;

//	get_signal();
//	while (1)
//	{
//		line = readline("minishell$ ");
//		found = 1;
//		if (!line)
//		{
//			printf("exit\n");
//			break ;
//		}
//		if (ft_strcmp(line, "exit") == 0)
//		{
//			free(line);
//			printf("exit\n");
//			break ;
//		}
//		if (ft_strncmp(line, "cd", 2) == 0)
//		{
//			tab = ft_split(line, ' ');
//			cmd_cd((const char **) tab, envp);
//			found = 0;
//		}
//		if (ft_strcmp(line, "ls") == 0)
//		{
//			pid = fork();
//			tab = ft_split(line, ' ');
//			if (pid == 0)
//			{
//				execve("/usr/bin/ls", tab, envp);
//				exit(1);
//			}
//			else
//				waitpid(pid, &status, 0);
//			found = 0;
//		}
//		if (line[0] != '\0' && found == 1)
//			printf("%s: command not found\n", line);
//		if (line[0] != '\0' && !empty_argument(line))
//			add_history(line);
//		free (line);
//	}
//	return (0);
//}

/* prend seulement les arguments non-vides */
