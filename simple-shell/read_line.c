#include "main.h"

ssize_t read_line(char **buffer, size_t *size, FILE *stream) {
    if (*buffer == NULL) {
        *size = MAX_INPUT_SIZE;
        *buffer = (char *)malloc(*size);
        if (*buffer == NULL) {
            perror("read_line: malloc error");
            return -1;
        }
    }

    ssize_t read;
    read = getline(buffer, size, stream);

    if (read == -1) {
        free(*buffer);
        *buffer = NULL;
    }

    return read;
}
