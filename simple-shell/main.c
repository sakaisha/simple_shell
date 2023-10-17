#include "main.h"
#include <unistd.h>

void display_prompt(void) {
    const char prompt[] = "$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

size_t mystrlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* mystrcpy(char *dest, const char *src) {
    char *original_dest = dest;

    while ((*dest++ = *src++) != '\0') {
        
    }

    return original_dest;
}

int mystrcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int main(int argc, char *argv[]) {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc == 1 || (argc == 2 && mystrcmp(argv[1], "-c") == 0)) {
        while (1) {
            char *tokens[MAX_TOKENS];
            display_prompt();
            if ((read = read_line(&input, &len, stdin)) == -1) {
                break; /* End of file (Ctrl+D) detected */
            }

            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Error: :( Failed to execute built-in command");
                }
            }
        }
    } else if (argc == 2 && mystrcmp(argv[1], "-c") != 0) {
        int file = open(argv[1], O_RDONLY);
        if (file == -1) {
            perror("Error: :( Unable to open the specified file");
            return EXIT_FAILURE;
        }

        while ((read = read_line(&input, &len, file)) != -1) {
            char *tokens[MAX_TOKENS];
            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Error: Failed to execute built-in command");
                }
            }
        }

        close(file);
    } else {
        perror("Usage: hsh [-c command | script-file]");
        return EXIT_FAILURE;
    }

    free(input);
    return EXIT_SUCCESS;
}