#include "main.h"

void display_error(char *message) {
    write(STDERR_FILENO, "Error: ", 7);
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, "\n", 1);
}