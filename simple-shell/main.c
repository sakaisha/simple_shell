#include "main.h"

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];

    if (argc == 1) {
        while (1) {
            display_prompt();
            if (read_line(input, MAX_INPUT_SIZE) == -1) {
                break; /* End of file (Ctrl+D) detected */
            }

            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }
    } else if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        while (read_line(input, MAX_INPUT_SIZE) != -1) {
            tokenize(input, tokens);

            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }

        fclose(file);
    } else {
        perror("Usage: hsh [file]");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}