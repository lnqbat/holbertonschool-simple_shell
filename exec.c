#include "shell.h"

/**
 * exec_command - execute command
 * @cmd: command to execute
 * Return: 0 on success,
 */

int exec_command(char *cmd)
{
	pid_t pid;
	int status, i;
	char **argv, *path_full;

	argv = tokenize(cmd);
	if (argv == NULL || argv[0] == NULL)
	{
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		return (-1);
	}
	if (access(argv[0], F_OK) == -1)
	{
		path_full = _which(argv[0]);
		if (path_full == NULL)
		{
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			return (-1);
		}
		else
		{
			free(argv[0]);
			argv[0] = path_full;
		}
	}
	pid = fork();
	if (pid == -1)
	{
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	return (0);
}
