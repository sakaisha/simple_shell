/* main.h */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 64

extern char **environ;

void display_error(char *message);
void display_prompt();
ssize_t read_line(char *buffer, size_t size);

int execute(char **args);
int cd_builtin(char **args);
int exit_builtin(char **args);
int pwd_builtin(char **args);
int echo_builtin(char **args);
int environ_builtin(char **args);
int execute_builtin(char **args);

void tokenize(char *input, char **tokens);

#endif /* MAIN_H */