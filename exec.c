#include "shell.h"

/**
 * exec_command - execute command
 * @argv: command tokenised to execute
 * @var: pointer of struct to last-status
 * Return: 0 on success,
 */
int exec_command(char **argv, variables_t *var)
{
	pid_t pid;
	int status;

	pid = fork();	/*launch process children*/

	if (pid == -1)
	{
		free_argv(argv);
		return (-1);
	}
	else if (pid == 0)	/*execute the file*/
	{
		if (execve(argv[0], argv, environ) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{	waitpid(pid, &status, 0);	/* Wait ending of processus children*/
		var->last_status = WEXITSTATUS(status);
	}
	free_argv(argv);
	return (0);
}
