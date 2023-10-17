#include "main.h"
#include <unistd.h>

int _setenv(data *d, const char *name, const char *value);

void builtin_setenv(data *d)
{
    (void)d;
    if (d->av[1] && d->av[2])
    {
        if (_setenv(d, d->av[1], d->av[2]) == -1)
        {
            perror("setenv");
        }
    }
}

void builtin_unsetenv(data *d)
{
    int i, j;
    int len;

    (void)d;
    if (!d->av[1] || !getenv(d->av[1]))
    {
        _perror(d->shell_name, "variable not found.");
        return;
    }
    len = strlen(d->av[1]);
    for (i = 0; environ[i]; i++)
        if (strncmp(environ[i], d->av[1], len) == 0 && environ[i][len] == '=')
            for (j = i; environ[j]; j++)
                environ[j] = environ[j + 1];
}
