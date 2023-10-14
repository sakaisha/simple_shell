#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

extern char **environ;

void handle_malloc_error(void);
void handle_getline_error(void);
void handle_fork_error(void);
void handle_execve_error(const char *command);
void handle_access_error(const char *command);
void handle_waitpid_error(void);

void executeCommand(char *command);

char *_getenv(const char *name);
void _setenv(const char *name, const char *value, int overwrite);
void _unsetenv(const char *name);

void printPathDirectories(void);

char **splitString(char *str, int *argc);

#endif  // MAIN_H
