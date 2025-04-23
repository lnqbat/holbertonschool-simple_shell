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
		if (check_builtin(argv, &last_status) == 0)	/* Check if builtin */
		{
			if ((strcmp(argv[0], "exit") == 0))	/* Handle exit return */
			{
				ret = exit_command(argv, &last_status);
				free_argv(argv);
				free(line);
				exit(ret);
			}
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
