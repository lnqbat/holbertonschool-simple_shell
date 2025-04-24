#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

extern char **environ;


/**
 * struct variables - allowing to use variables everywhere
 *@last_status;
 *@mode_matrix;
 */

typedef struct variables
{
	int last_status;
	int mode_matrix;
} variables_t;

void print_prompt(variables_t *var);
char *read_input(void);

char **tokenize(char *line);
char *_getenv(char *name);
int free_argv(char **argv);
int _atoi(char *s);
int exit_command(char **argv, variables_t *var);
char **find_path(char **argv, char *line);
int exec_command(char **argv, variables_t *var);
int env_builtin(char **argv, variables_t *var);

char *_which(const char *filename);
int check_builtin(char **argv, variables_t *var);
int quit(char **argv, variables_t *var);
int dramatic_intro(char **argv, variables_t *var);
int print_ascii(char **argv, variables_t *var);
int print_ascii_2(char **argv, variables_t *var);
int help_command(char **argv, variables_t *var);
/**
 * struct builtin - structur containig builtins
 *@name: alias command
 *@func: function linked to name
 */

typedef struct builtin
{
	char *name;
	int (*func)(char **argv, variables_t *var);
} builtin;
#endif
