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
		if (strcmp(argv[0], "env") == 0)
		{
			env_builtin();
			free_argv(argv);
			free(line);
			continue;
		}
		argv = find_path(argv, line);
		exec_command(argv, &last_status);
		free(line);
	}
	return (last_status);
}
