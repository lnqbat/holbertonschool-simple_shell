#include "shell.h"

/**
 * print_promt - print prompt
 *
 */

void print_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * read_imput - read input
 * Return: line
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
