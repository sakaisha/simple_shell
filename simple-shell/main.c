// main.c

#include "main.h"
#include <unistd.h>

void display_prompt(void) {
    const char prompt[] = "$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

int main(int argc, char *argv[]) {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-c") == 0)) {
        while (1) {
            char *tokens[MAX_TOKENS];
            display_prompt();
            if ((read = read_line(&input, &len, stdin)) == -1) {
                break; /* End of file (Ctrl+D) detected */
            }

            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }
    } else if (argc == 2 && strcmp(argv[1], "-c") != 0) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        while ((read = read_line(&input, &len, file)) != -1) {
            char *tokens[MAX_TOKENS];
            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }

        fclose(file);
    } else {
        perror("Usage: hsh [-c command | script-file]");
        return EXIT_FAILURE;
    }

    free(input);
    return EXIT_SUCCESS;
}
