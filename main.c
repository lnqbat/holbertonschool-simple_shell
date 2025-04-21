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
		is_prompt = isatty(STDIN_FILENO);	/*Check if is intéractive mode*/
		if (is_prompt == 1)
			print_prompt();

		line = read_input();			/* Keep user commmande*/
		if (line == NULL)
			break;

		argv = tokenize(line);			/* Extract command to token*/
		if (argv == NULL || argv[0] == NULL)
		{
			free_argv(argv);
			free(line);
			continue;
		}
		ret = exit_command(argv, &last_status); /* Check builtin exit command*/
		if (ret >= 0)
		{
			free_argv(argv);
			free(line);
			exit(ret);
		}
		if (strcmp(argv[0], "env") == 0)	/* Check builtin env command*/
		{
			env_builtin();
			free_argv(argv);
			free(line);
			continue;
		}
		argv = find_path(argv, line);		/* Complete path to execute command*/
		exec_command(argv, &last_status);	/* Execute command*/
		free(line);
	}
	return (last_status);
}
