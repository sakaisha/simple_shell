#include "main.h"

int main(int argc, char *argv[]) {
    // Check if command-line arguments are provided
    if (argc > 1) {
        executeCommand(argv[1]);
        return 0;
    }

    // If no command-line arguments, run the interactive shell
    char *command = NULL;
    size_t len = 0;
    ssize_t read_bytes;

    setup_signal_handlers(); 
    while (1) {
        write(1, "> ", 2);

        command = (char *)malloc(BUFF_SIZE);
        if (command == NULL) {
            handle_malloc_error();
        }

        read_bytes = getline(&command, &len, stdin);

        if (read_bytes == -1) {
            if (feof(stdin)) {
                free(command);
                break;
            } else if (ferror(stdin)) {
                handle_getline_error();
                free(command);
                continue;
            }
        }

        if (command[read_bytes - 1] == '\n') {
            command[read_bytes - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            free(command);
            break;
        }

        executeCommand(command);

        free(command);
    }

    return 0;
}

