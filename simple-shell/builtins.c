#include "main.h"

int pwd_builtin(char **args) {
    (void)args; 
    char cwd[MAX_INPUT_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        write(STDOUT_FILENO, cwd, strlen(cwd));
        write(STDOUT_FILENO, "\n", 1);
    } else {
        perror("pwd: error getting current directory");
    }
    return 0;
}

int environ_builtin(char **args) {
    (void)args;
    extern char **environ;
    char **env;
    for (env = environ; *env != NULL; env++) {
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
    }
    return 0;
}
