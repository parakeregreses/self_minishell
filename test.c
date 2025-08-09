#include "minishell.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	main(void)
{

	struct stat	buf;
	int			status;

	status = lstat("./note.txt", &buf);
	ft_printf("status = %d\n", status);
	if (status != 0)
		return (0);
	if (S_ISDIR(buf.st_mode))
		ft_printf("directory\n");
	else
		ft_printf("not directory\n");
	// ft_printf("%d\n", access(, F_OK));
	// ft_printf("%d\n", access("execution", F_OK));
	// ft_printf("%d\n", access("./note.txt", F_OK));
	// ft_printf("%d\n", access("note.txt", F_OK));
	// ft_printf("%d\n", access("./bullshit", F_OK));
	// ft_printf("%d\n", access("bullshit", F_OK));
}