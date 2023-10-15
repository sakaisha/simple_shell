#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// Data structure to hold shell information
typedef struct {
    char *cmd;
    char **av;
    char *shell_name;
    int last_exit_status;
} data;

#define PROMPT "$ "

extern char **environ;
int _setenv(data *d, const char *name, const char *value);

// Function declarations
void init_data(data *d, const char *shell_name);
void _printf(const char *format, ...);
void read_cmd(data *d);
size_t _strlen(const char *str);
char *_strdup(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
void free_array(char **arr);
void handler_sigint(int sig);
void start_process(data *d);
int exec_builtin(data *d);
void _which(data *d);
void _perror(const char *str1, const char *str2);
void _exec(data *d);
void builtin_setenv(data *d);
void builtin_unsetenv(data *d);
void split(data *d, const char *delim);
char *_getenv(char *name);
void builtin_env(data *d);
void handle_error(data *d, const char *message);
void handle_malloc_error(data *d);
void handle_fork_error(data *d);
void handle_exec_error(data *d);
void handle_wait_error(data *d);

#endif /* MAIN_H */

