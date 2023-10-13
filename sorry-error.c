#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void handle_malloc_error(void)
{
    write(2, "sorry error :(\n", 15);
    exit(EXIT_FAILURE);
}

void handle_getline_error(void)
{
    write(2, "sorry error :(\n", 15);
    exit(EXIT_FAILURE);
}

void handle_fork_error(void)
{
    write(2, "sorry error :(\n", 15);
    exit(EXIT_FAILURE);
}

void handle_execve_error(const char *command)
{
    perror(command);
    exit(EXIT_FAILURE);
}

void handle_access_error(const char *command)
{
    write(2, "sorry error :(\n", 15);
    exit(EXIT_FAILURE);
}

void handle_waitpid_error(void)
{
    write(2, "sorry error :(\n", 15);
    exit(EXIT_FAILURE);
}
