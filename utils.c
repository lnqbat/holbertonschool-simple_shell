#include "shell.h"

/**
 * free_argv - free array
 * @argv: the array to free.
 */

void free_argv(char **argv)
{
	int i = 0;

	if (!argv)
		return;

	while (argv[i])
		free(argv[i++]);
	free(argv);
}


/**
 *
 *
 */

int have_slash(char *argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		if (argv[i] == '/')
			return (1);
	}
	return (0);
}
