#include "main.h"

void split(data *d, const char *delim)
{
    char *token;
    int ntoken = 0;

    d->av = malloc(2 * sizeof(char *));
    if (d->av == NULL)
    {
        free(d->cmd);
        perror(d->shell_name);
        exit(EXIT_FAILURE);
    }
    d->av[0] = NULL;
    d->av[1] = NULL;

    token = strtok(d->cmd, delim);
    while (token)
    {
        d->av = realloc(d->av, (ntoken + 2) * sizeof(char *));
        if (d->av == NULL)
            goto free;
        d->av[ntoken] = _strdup(token);
        if (d->av[ntoken] == NULL)
            goto free;
        ntoken++;
        token = strtok(NULL, delim);
    }
    d->av[ntoken] = NULL;
    return;
free:
    free_array(d->av);
    free(d->cmd);
    perror(d->shell_name);
    exit(EXIT_FAILURE);
}

