#include "main.h"

int cd_builtin(char **args) {
    if (args[1] == NULL) {
        perror("cd: missing argument");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd: cannot change directory");
        }
    }
    return 0;
}

int exit_builtin(char **args) {
    (void)args;
    _exit(0);
}

int pwd_builtin(char **args) {
    char cwd[MAX_INPUT_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        write(STDOUT_FILENO, cwd, strlen(cwd));
        write(STDOUT_FILENO, "\n", 1);
    } else {
        write(STDERR_FILENO, "pwd: error getting current directory\n", 36);
    }
    return 0;
}

int echo_builtin(char **args) {
    int i = 1;
    while (args[i] != NULL) {
        write(STDOUT_FILENO, args[i], strlen(args[i]));
        write(STDOUT_FILENO, " ", 1);
        i++;
    }
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}

int environ_builtin(char **args) {
    (void)args;
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
    }
    return 0;
}