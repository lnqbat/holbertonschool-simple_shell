#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * main - Super simple shell
 * Return: ouille if close
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	char *argv[2] = {NULL, NULL};
	int status;

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

		argv[0] = line;
		argv[1] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Aie aie aie");
			break;
		}
		if (pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
				perror("execve");
			free(line);
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
