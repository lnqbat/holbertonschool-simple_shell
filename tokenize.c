#include "shell.h"
/**
* tokenize - parse command line
* @cmd: pointer to tokenise
* Return: array of string
*/

char **tokenize(char *cmd)
{
	char **argv = NULL;
	int bsize = 80, i = 0;
	char *token;

	argv = malloc(sizeof(char *) * bsize);
	if (argv == NULL)
	{
		free(cmd);
		return (NULL);
	}

	token = strtok(cmd, " \t\n");

	while (token != NULL && i < bsize)
	{
		argv[i] = strdup(token);
		
		if (argv[i] == NULL)
		{
			free(cmd);
			for (;i > 0; i--)
				free(argv[i]);
			free(argv);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (argv);
}
