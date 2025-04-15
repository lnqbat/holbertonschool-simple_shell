#include "shell.h"

/**
 * main - Entry point of the shell
 * Return: Always 0
 */

int main(void)
{
	char *line;
	int i;
	int is_prompt;
	while (1)
	{
		is_prompt = isatty(STDIN_FILENO);
		if(is_prompt == 1)
			print_prompt();

		line = read_input();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0')
		{
			free(line);
			continue;
		}
		exec_command(line);
		free(line);
	}
	return (0);
}
