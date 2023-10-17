#include "main.h"

void display_error(char *message) {
    write(STDERR_FILENO, "Error: ", 7);
    write(STDERR_FILENO, message, string_length(message));
    write(STDERR_FILENO, "\n", 1);
}
