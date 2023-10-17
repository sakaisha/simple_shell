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

void execute_command(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        command = argv[0];
        actual_command = get_path(command);

        if (actual_command == NULL) {
            write(STDERR_FILENO, "execute_command: command not found\n", 35);
            return;
        }

        if (execve(actual_command, argv, NULL) == -1) {
            write(STDERR_FILENO, "execute_command: execve error\n", 30);
        }

        free(actual_command);
    }
}

int execute_builtin(char **args) {
    if (args[0] == NULL) {
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
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            
            if (execvp(args[0], args) == -1) {
                write(STDERR_FILENO, "hsh: command not found: ", 24);
                write(STDERR_FILENO, args[0], strlen(args[0]));
                write(STDERR_FILENO, "\n", 1);
            }
            _exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("hsh");
        } else {
            
            do {
                status = 0;  
                if (waitpid(pid, &status, WUNTRACED) == -1) {
                    perror("waitpid");
                    status = -1; 
                    break;
                }
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        return status;
    }

    return -1;
}