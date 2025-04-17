#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void print_prompt(void);
char *read_input(void);

char **tokenize(char *cmd);
char *_getenv(char *name);
void free_argv(char **argv);
int exec_command(char *cmd);
char *_which(const char *filename);

#endif
