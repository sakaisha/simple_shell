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

extern char **environ; // Declare the external variable environ

void executeCommand(char *command);

void handle_malloc_error(void);
void handle_getline_error(void);
void handle_fork_error(void);
void handle_execve_error(const char *command);
void handle_access_error(const char *command);
void handle_waitpid_error(void);

#endif  // MAIN_H
