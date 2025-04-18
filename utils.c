#include "shell.h"

/**
 * free_argv - free array
 * @argv: the array to free.
 */

int free_argv(char **argv)
{
	int i = 0;

	if (!argv)
		return (-1);

	while (argv[i])
		free(argv[i++]);
	free(argv);

	return (0);
}

