#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 1024

extern char **environ;  // Declare the environment variable

void handle_malloc_error();
void handle_getline_error();
void handle_fork_error();
void handle_access_error(char *command);
void handle_execve_error(char *command);
void handle_waitpid_error();

int main(int argc, char *argv[]);

#endif /* MAIN_H */
