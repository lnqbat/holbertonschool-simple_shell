#include "shell.h"

/**
 * _getenv - Get an environment variable
 * @name: The name of the environment variable
 * Return: environment variable
 */

char *_getenv(char *name)
{
	char **env = environ;
	size_t len = strlen(name);

	while (*env != NULL)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			// PATH=/home/... => /home/...
			return (*env + (len + 1));
		}
		env++;
	}
	return (NULL);
}

