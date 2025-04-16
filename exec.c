#include "shell.h"

/**
 * exec_command - execute command
 * @cmd: command to execute
 * Return: 0 on success,
 */

int exec_command(char *cmd)
{
	pid_t pid;
	int status;
	char **argv, *path_full;

	argv = tokenize(cmd);
	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return (-1);
	}
	if (access(argv[0], F_OK) == -1)
	{
		path_full = _which(argv[0]);
		if (path_full == NULL)
		{
			free(argv);
			return (-1);
		}
		else
			argv[0] = path_full;
	}
	pid = fork();
	if (pid == -1)
	{
		free(argv);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(path_full);
	free(argv);
	return (0);
}
