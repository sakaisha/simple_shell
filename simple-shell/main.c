#include "main.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char *input = NULL;
        size_t len = 0;
        ssize_t read;

        while (1) {
            display_prompt();
            if ((read = getline(&input, &len, stdin)) == -1) {
                break; /* End of file (Ctrl+D) detected */
            }

            char *tokens[MAX_TOKENS];
            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }

        free(input);
    } else if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        char *input = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&input, &len, file)) != -1) {
            char *tokens[MAX_TOKENS];
            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }

        fclose(file);
        free(input);
    } else {
        perror("Usage: hsh [file]");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
