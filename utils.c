#include "shell.h"

/**
 * free_argv - free array
 * @argv: the array to free.
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
