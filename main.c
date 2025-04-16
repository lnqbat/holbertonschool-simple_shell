#include "shell.h"

/**
 * main - Entry point of the shell
 * Return: Always 0
 */

int main(void)
{
	char *line;
	int is_prompt;

	while (1)
	{
		is_prompt = isatty(STDIN_FILENO);
		if (is_prompt == 1)
			print_prompt();

		line = read_input();
		if (line == NULL)
			break;

		exec_command(line);
		free(line);
	}
	return (0);
}
