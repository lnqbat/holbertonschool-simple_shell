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

void print_prompt(void);
char *read_input(void);

char **tokenize(char *cmd);
char *_getenv(char *name);
int free_argv(char **argv);
int _atoi(char *s);
int exit_command(char **argv);

int exec_command(char *cmd);
char *_which(const char *filename);
#endif
