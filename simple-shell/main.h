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

// Function declarations
void display_error(char *message);
void display_prompt();
ssize_t read_line(char *buffer, size_t size);

char *builtin_str[] = {
    "cd",
    "exit",
    "pwd",
    "echo",
    "environ"
};

int (*builtin_func[])(char **) = {
    &cd_builtin,
    &exit_builtin,
    &pwd_builtin,
    &echo_builtin,
    &environ_builtin
};

int cd_builtin(char **args);
int exit_builtin(char **args);
int pwd_builtin(char **args);
int echo_builtin(char **args);
int environ_builtin(char **args);
int execute_builtin(char **args);

void tokenize(char *input, char **tokens);
void display_error(char *message);
void display_prompt();
ssize_t read_line(char *buffer, size_t size);

#endif /* MAIN_H */
