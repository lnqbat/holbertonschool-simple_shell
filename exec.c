#include "shell.h"

/**
 * exec_command - execute command
 * @command: command to execute
 * Return: 0 on success,
 */

int exec_command(char *cmd)
{
	pid_t pid;
	int status;
	char **argv;

	argv = tokenize(cmd);
	if (argv[0] == NULL || argv == NULL)
	{
		perror("tokenization !");
		return (-1);
	}
	if(access(argv[0], X_OK) == - 1)
	{
		perror("command not found");
		free(argv);
		return (-1);
	}
	/**
	argv[0] = cmd;
	argv[1] = NULL;
*/
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
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
	{
		wait(&status);
	}
	free(argv);
	return (0);
}
