#include "shell.h"

/**
 * main - Entry point of the shell
 * Return: Always 0
 */

int main(void)
{
	char *line;
	int is_prompt, ret, last_status = 0;
	char **argv;

	while (1)
	{
		is_prompt = isatty(STDIN_FILENO);
		if (is_prompt == 1)
			print_prompt();

		line = read_input();
		if (line == NULL)
			break;

		argv = tokenize(line);
		if (argv == NULL || argv[0] == NULL)
		{
			free_argv(argv);
			free(line);
			return (-1);
		}
		ret = exit_command(argv, &last_status);
		if (ret >= 0)
		{
			free_argv(argv);
			free(line);
			exit(ret);
		}

		exec_command(argv, line, &last_status);
		free(line);
	}
	return (0);
}
