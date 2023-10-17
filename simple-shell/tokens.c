#include "main.h"

void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " \t\n\r");
    int i = 0;

    while (token != NULL && i < MAX_TOKENS - 1) {
        tokens[i++] = token;
        token = strtok(NULL, " \t\n\r");
    }

    tokens[i] = NULL; // Null-terminate the array of tokens
}