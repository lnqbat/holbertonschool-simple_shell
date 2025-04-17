#include "shell.h"

/**
 * exec_command - execute command
 * @cmd: command to execute
 * Return: 0 on success,
 */

int exec_command(char *cmd)
{
	pid_t pid;
	int status, slashed;
	char **argv, *path_full;

	argv = tokenize(cmd);
	if (argv == NULL || argv[0] == NULL)
	{
		free_argv(argv);
		return (-1);
	}
	slashed = have_slash(argv[0]);
	if (slashed == 1)
	{
		path_full = _which(argv[0]);
		if (path_full == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			free_argv(argv);
			free(cmd);
			exit(127);
		}
		else
		{
			free(argv[0]);
			argv[0] = path_full;
		}
	}
	else if (access(argv[0], F_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			free_argv(argv);
			return (-1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	free_argv(argv);
	return (0);
}
