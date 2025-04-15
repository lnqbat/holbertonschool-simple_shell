#include "shell.h"

/**
 * main - simple shell
 *
 * Return: Always 0 .
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	char *argv[] = {line, NULL};

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("Ouille");
			break;
		}

		if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("Aie aie aie");
			break;
		}
		if (pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("execve");
			}
			exit(1);
		}
		else
			wait(NULL);
	}
	free(line);
	return (0);
}

