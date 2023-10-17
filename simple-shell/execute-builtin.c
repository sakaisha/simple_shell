#include "main.h"

char *get_path(char *command) {
    char *path_copy, *token, *path;
    size_t token_len, command_len, path_len, written;

    char *path_env = getenv("PATH");
    if (path_env == NULL) {
        perror("get_path: getenv error");
        return NULL;
    }

    size_t path_env_len = 0;
    while (path_env[path_env_len] != '\0') {
        ++path_env_len;
    }

    path_copy = (char *)malloc(path_env_len + 1);
    if (path_copy == NULL) {
        perror("get_path: malloc error");
        return NULL;
    }

    for (size_t i = 0; i <= path_env_len; ++i) {
        path_copy[i] = path_env[i];
    }

    path = NULL;
    token = strtok(path_copy, ":");
    while (1) {
        if (token == NULL) {
            break;
        }

        token_len = 0;
        while (token[token_len] != '\0') {
            ++token_len;
        }

        command_len = 0;
        while (command[command_len] != '\0') {
            ++command_len;
        }

        path_len = token_len + command_len + 2;

        path = (char *)malloc(path_len);

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
            return path;
        }

        free(path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}