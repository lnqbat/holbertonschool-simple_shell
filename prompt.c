#include "shell.h"

/**
 * print_prompt - print prompt
 * Return: No needed just print
 */

void print_prompt(variables_t *var)
{
	if (var->mode_matrix == 1)
		printf("\033[1;32m#matrix$ ");
	else
		printf("\033[0m#cisfun$ ");
}

/**
 * read_input - read input
 * Return: line keeped
 */

char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[nread - 1] == '\n')
	line[nread - 1] = '\0';

	return (line);
}
