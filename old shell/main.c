#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void) {
    const char prompt[] = "$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

char* string_token(char* str, const char* delim) {
    static char* save_ptr;
    char* token;
    if (str != NULL) {
        save_ptr = str;
    } else {
        if (save_ptr == NULL || *save_ptr == '\0') {
            return NULL;
        }
    }
    while (*save_ptr != '\0' && strchr(delim, *save_ptr) != NULL) {
        save_ptr++;
    }
    if (*save_ptr == '\0') {
        return NULL;
    }
    token = save_ptr;
    while (*save_ptr != '\0' && strchr(delim, *save_ptr) == NULL) {
        save_ptr++;
    }
    if (*save_ptr != '\0') {
        *save_ptr = '\0';
        save_ptr++;
    }
    return token;
}

void executeCommand(char *command) {
    pid_t pid = fork();
    char *envp[] = {NULL}; 
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { 
        char *args[MAX_COMMAND_LENGTH];
        char *token = string_token(command, " \t\n");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = string_token(NULL, " \t\n");
        }
        args[i] = NULL;
        if (execve(args[0], args, envp) == -1) {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    } else { 
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        display_prompt();
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "exit") == 0) {
            printf("Exiting the shell.\n");
            break;
        }
        executeCommand(command);
    }
    return 0;
}