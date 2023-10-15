#include "main.h"

void handle_error(data *d, const char *message)
{
    _perror(d->shell_name, message);
    d->last_exit_status = EXIT_FAILURE;
}

void handle_malloc_error(data *d)
{
    handle_error(d, "memory allocation error");
    exit(d->last_exit_status);
}

void handle_fork_error(data *d)
{
    handle_error(d, "fork error");
    exit(d->last_exit_status);
}

void handle_exec_error(data *d)
{
    handle_error(d, "exec error");
    exit(d->last_exit_status);
}

void handle_wait_error(data *d)
{
    handle_error(d, "wait error");
    exit(d->last_exit_status);
}

