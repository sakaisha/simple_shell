// main.h

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 1024
#define MAX_ARGS 64

extern char **environ;

void executeCommand(char *command);
void setup_signal_handlers(void);
void handle_malloc_error(void);
void handle_getline_error(void);
void handle_fork_error(void);
void handle_execve_error(char *cmd);
void handle_command_not_found(char *cmd);
int is_valid_command(char *cmd);
void print_not_found_error(char *program, char *cmd, int count);
void print_permission_error(char *program, char *cmd, int count);
int custom_strlen(char *str);  // Include the custom_strlen function

char *_getenv(const char *name);
void _setenv(const char *name, const char *value, int overwrite);
void _unsetenv(const char *name);

void printPathDirectories(void);

char **splitString(char *str, int *argc);

#endif // MAIN_H
