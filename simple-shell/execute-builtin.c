#include "main.h"

char *get_path(char *command) {
    char *path_copy = strdup(getenv("PATH"));
    if (path_copy == NULL) {
        perror("get_path: strdup error");
        return NULL;
    }

    char *token = strtok(path_copy, ":");
    size_t written;

    while (1) {
        if (token == NULL) {
            break;
        }

        size_t token_len = strlen(token);
        size_t command_len = strlen(command);
        size_t path_len = token_len + command_len + 2;

        char *path = (char *)malloc(path_len);
        if (path == NULL) {
            perror("get_path: malloc error");
            free(path_copy);
            return NULL;
        }

        written = write(STDOUT_FILENO, token, token_len);
        written += write(STDOUT_FILENO, "/", 1);
        written += write(STDOUT_FILENO, command, command_len);
        write(STDOUT_FILENO, "\0", 1);

        if (access(path, X_OK) == 0) {
            free(path_copy);
            free(path);  // Free the allocated path before returning
            return path;
        }

        free(path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

void execute_command(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        command = argv[0];
        actual_command = get_path(command);

        if (actual_command == NULL) {
            perror("execute_command: command not found");
            return;
        }

        if (execve(actual_command, argv, NULL) == -1) {
            perror("execute_command: execve error");
        }

        free(actual_command);
    }
}

int execute_builtin(char **args) {

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
