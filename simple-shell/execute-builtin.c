#include "main.h"

extern char **environ;

void write_int(int num) {
    char buffer[16];
    int length = 0;
    while (num > 0) {
        buffer[length++] = '0' + num % 10;
        num /= 10;
    }
    if (length == 0) {
        buffer[length++] = '0';
    }
    while (length > 0) {
        write(STDOUT_FILENO, &buffer[--length], 1);
    }
}

int execute_builtin(char **args) {
    if (args[0] == NULL) {
        /* An empty command was entered */
        return 1;
    }

    if (strcmp(args[0], "cd") == 0) {
        return cd_builtin(args);
    } else if (strcmp(args[0], "exit") == 0) {
        return exit_builtin(args);
    } else if (strcmp(args[0], "pwd") == 0) {
        return pwd_builtin(args);
    } else if (strcmp(args[0], "echo") == 0) {
        return echo_builtin(args);
    } else if (strcmp(args[0], "environ") == 0) {
        return environ_builtin(args);
    } else {
        /* External command */
        pid_t pid, wpid;
        int status;

        pid = fork();
        if (pid == 0) {
            /* Child process */
            /* Remaining code unchanged */
        } else if (pid < 0) {
            /* Fork error */
            perror("hsh");
        } else {
            /* Parent process */
            do {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        return 0;
    }

    return -1; /* Not a builtin command */
}