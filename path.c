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

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		len = strlen(token) + strlen(filename) + 2;
		full_path = (char *)malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
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

