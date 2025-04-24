#include "shell.h"

/**
 * help_command - hep function that help
 * @argv: not used
 * @var: not used
 * Return: 0 .
 */

int help_command(char **argv, variables_t *var)
{
	(void) argv;
	(void) var;

	printf("Shell Help:\n");
	printf("Available built-in commands:\n");
	printf("  exit    - Exit the shell.\n");
	printf("  env     - Display the environment variables.\n");
	printf("  help    - Display information about built-in commands.\n");
	printf("  Otherwise, manage on your own !\n");

	return (0);
}
