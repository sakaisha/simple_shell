#include "main.h"

char *find_env_var(char *var) {
    int i = 0, j;
    int match;

    while (environ[i]) {
        match = 1;

        for (j = 0; environ[i][j] != '='; j++) {
            if (environ[i][j] != var[j])
                match = 0;
        }

        if (match)
            break;

        i++;
    }

    return (match) ? (&environ[i][j + 1]) : NULL;
}

void print_env(void) {
    int i = 0;

    while (environ[i]) {
        write(STDOUT_FILENO, environ[i], string_length(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

char *getenv_builtin(char **args) {
    if (args[1] == NULL) {
        write(STDERR_FILENO, "getenv: missing argument\n", 25);
        return NULL;
    }

char *getenv_builtin(char **args) {
    if (args[1] == NULL) {
        write(STDERR_FILENO, "getenv: missing argument\n", 25);
        return NULL;
    }

    char *value;
    value = getenv(args[1]);

    if (value == NULL) {
        write(STDERR_FILENO, "getenv: variable not found\n", 28);
    } else {
        write(STDOUT_FILENO, value, string_length(value));
        write(STDOUT_FILENO, "\n", 1);
    }

    return value;
}
