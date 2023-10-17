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

    if (argc == 1 || (argc == 2 && string_compare(argv[1], "-c") == 0)) {
        while (1) {
            char *tokens[MAX_TOKENS];
            display_prompt();
            if ((read = read_line(&input, &len, stdin)) == -1) {
                break; /* EOF */
            }
            tokenize(input, tokens);
            if (tokens[0] != NULL) {
                if (execute_builtin(tokens) == -1) {
                    perror("Execution failed");
                }
            }
        }
    } else {
        perror("Failed to execute the command");
        return EXIT_FAILURE;
    }

    free(input);
    return EXIT_SUCCESS;
}
