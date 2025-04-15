#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


char *_which(char *filename)
{
	char *path;
	char *path_copy;
	char *path_token;
	char *path_full;
	size_t path_len, file_len, total;

	
	path = getenv("PATH");
	path_copy = strdup(path);
	path_token = strtok(path_copy, ":");

	while(path_token)
	{
		path_len = strlen(path_token);
		file_len = strlen(filename);
		total = path_len + file_len + 2;
		path_full = (char *)malloc(total);
		if (path_full == NULL)
			exit(1);

		strcpy(path_full, path_token);
		strcat(path_full, "/");
		strcat(path_full, filename);

		if (access(path_full, F_OK) == 0)
		{
			free(path_copy);
			return (path_full);
			free(path_full);
		}
		path_token = strtok(NULL, ":");
		free(path_full);
	}
	free(path_copy);
	return (NULL);
}

/**
 *
 *
 *
 */

int main(int ac, char **argv)
{
	char *result;
	int i = 1;

	if (ac < 2)
		return (1);

	while (i < ac)
	{
		result = _which(argv[i]);
		if (result != NULL)
			printf("%s found!\n", result);
		else
			printf("%s not found!\n", argv[i]);
		i++;
	}
	free(result);
	return (0);
}
