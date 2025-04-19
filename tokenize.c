#include "shell.h"

/**
 * tokenize - Split a command line into tokens (words)
 * @line: the command line to tokenize
 * Return: A NULL-terminated array of strings (tokens)
 */

char **tokenize(char *line)
{
	char **argv;
	int bsize = 80, j, i = 0;
	char *token;

	argv = malloc(sizeof(char *) * bsize);
	if (argv == NULL)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token != NULL && i < bsize - 1)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}
