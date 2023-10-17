#include "main.h"

int main(int argc, char *argv[]) {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc == 1) {
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
    } else if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            free(input);  
            return EXIT_FAILURE;
        }

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
    } else {
        perror("Usage: hsh [file]");
        free(input); 
        return EXIT_FAILURE;
    }

    free(input);  
    return EXIT_SUCCESS;
}
