#include "minishell.h"

int	main(void)
{
	printf("%d\n", unlink("bullsit"));
	printf("%d\n", unlink("bullshit"));
	perror("");

}