#include "shell.h"

/**
 * free_argv - free array
 * @argv: the array to free.
 * Return: 0 if sucess
 */

int free_argv(char **argv)
{
	int i = 0;

	if (!argv)
		return (-1);

	while (argv[i])
		free(argv[i++]);
	free(argv);

	return (0);
}

/**
 **_atoi - to convert a char in int
 *@s: pointer type char
 *Return: return int
 */
int _atoi(char *s)
{
	int i, is_minus;
	unsigned int result;

	i = 0;
	result = 0;
	is_minus = 1;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			is_minus *= -1;

		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{

		result = result * 10 + (s[i] - '0');

		if (is_minus == 1 && result > (unsigned int)INT_MAX)
		{
			return (INT_MAX);
		}
		if (is_minus == -1 && result > (unsigned int)INT_MAX + 1)
		{
			return (INT_MIN);
		}

		i++;
	}

	return ((int)result * is_minus);
}

/**
 * exit_command - Handles the built-in 'exit' command
 * @argv: array of command arguments
 * @last_status: to exit with last status of processus children
 * Return:  'exit' was handled
 */

int exit_command(char **argv, int *last_status)
{
	int exit_code;

	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit_code = _atoi(argv[1]);
		else
			exit_code = *last_status;

		return (exit_code);
	}
	return (-1);
}

/**
 * env_builtin - Prints all environment variables to standard output
 * @i: counter loop env
 */

int env_builtin(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
