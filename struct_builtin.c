#include "shell.h"

/**
 * check_builtin - handle builtins commands
 * @argv: command to check
 * @last_status: only for exit command
 * Return: 0 if success
 */

int check_builtin(char **argv, variables_t *var)
{
	int i;

	builtin builtins[] = {
		{"exit", exit_command},
		{"env", env_builtin},
		{"matrix", dramatic_intro},
		{"hugo", print_ascii},
		{"fabien", print_ascii_2},
		{"help", help_command},
		{"quit", quit},
		{NULL, NULL}
	};


	for (i = 0; builtins[i].name; i++)
	{
		if (strcmp(argv[0], builtins[i].name) == 0)	/* Check if builtin */
		{
			if (strcmp(argv[0], "exit") == 0)
				return (0);

			builtins[i].func(argv, var);	/* if that execute function */
			return (0);
		}
	}
	return (1);
}
