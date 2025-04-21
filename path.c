#include "shell.h"

/**
 * _which - Search the full path of (shell) commands
 * @filename: pointer comand call
 * Return: PATH or NULL .
 */

char *_which(const char *filename)
{
	char *path;
	char *path_copy;
	char *token;
	size_t len;
	char *full_path;

	path = _getenv("PATH");	/* Keep env in varible*/
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);	/* Copy path to protect it*/
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":"); /* Sort all element of path*/

	while (token != NULL)
	{
		len = strlen(token) + strlen(filename) + 2;
		full_path = (char *)malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(full_path, token);	/* Attribute to full_path all possibility */
		strcat(full_path, "/");		/* And chek with access if exist*/
		strcat(full_path, filename);

		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * find_path - find path of command lauched
 * @argv: command tokenised to execute
 * @line: need to free if necessaire
 * Return: a complete path of command called in argv[0]
 */

char **find_path(char **argv, char *line)
{
	char *path_full;

	if (!strchr(argv[0], '/'))	/* Control if containig '/'*/
	{
		path_full = _which(argv[0]);	/*return complet path in variable*/
		if (path_full == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			free_argv(argv);
			free(line);
			exit(127);
		}
		else
		{
			free(argv[0]);
			argv[0] = path_full;
		}
	}
	if (access(argv[0], X_OK) == -1)	/* Check if executable is accessible*/
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free_argv(argv);
		free(line);
		exit(127);
	}

	return (argv);

}
