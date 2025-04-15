#include "shell.h"
/**
* tokenize - parse command line
* @cmd: pointer to tokenise
* Return: array of string
*/

char **tokenize(char *cmd)
{
	char **argv;
	int bsize = 80, i = 0;
	char *token;

	argv = malloc(sizeof(char*) * bsize);
	if (argv == NULL)
		return NULL;
	token = strtok(cmd, " \t\n");
	while (token != NULL && i < bsize -1)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}
