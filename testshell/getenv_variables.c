#include "main.h"

void builtin_env(data *d)
{
    int i;

    (void)d;
    if (environ == NULL)
        return;
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

