#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	size_t size = 0;
	ssize_t read;
	char *line = NULL;
	char *token;
	char *separator = " \n";
	while (1)
	{
		printf("$ ");
		read = getline(&line, &size, stdin);
			if (read == -1)
			{
				_exit(1);
			}

		token = strtok(line, separator);
		while (token != NULL)
		{
			printf("%s\n", token);

			token = strtok(NULL, separator);
		}
	}
	free(line);
	return (0);
}
