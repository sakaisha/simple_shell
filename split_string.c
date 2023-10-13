#include <unistd.h>
#include <string.h>

#define MAX_ARGS 64

char **splitString(char *str, int *argc)
{
    char **args = malloc(MAX_ARGS * sizeof(char *));
    if (args == NULL)
    {
        perror("Error allocating memory");
        _exit(EXIT_FAILURE);
    }

    char *token = strtok(str, " \t\n");
    int count = 0;

    while (token != NULL)
    {
        args[count] = strdup(token);
        if (args[count] == NULL)
        {
            perror("Error allocating memory");
            _exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " \t\n");
        count++;
    }

    args[count] = NULL;
    *argc = count;

    return args;
}

