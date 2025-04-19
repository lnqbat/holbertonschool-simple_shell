#include "shell.h"

/**
 * exec_command - execute command
 * @argv: command tokenised to execute
 * @line: need to free if necessaire
 * @last_status: pointer to keep the status of processus children
 * Return: 0 on success,
 */
int exec_command(char **argv, char *line, int *last_status)
{
	pid_t pid;
	int status;
	char *path_full;

	if (!strchr(argv[0], '/'))
	{
		path_full = _which(argv[0]);
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
	if (access(argv[0], X_OK) == -1)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free_argv(argv);
		free(line);
		exit(127);
	}
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
	{	waitpid(pid, &status, 0);
		*last_status = WEXITSTATUS(status);
	}
	free_argv(argv);
	return (0);
}
