#include "main.h"

char *_getenv(char *name)
{
    int i = -1;
    size_t name_len;

    if (name == NULL || *name == '\0')
        return (NULL);
    if (environ == NULL)
        return (NULL);

    name_len = _strlen(name);

    while (environ[++i])
    {
        if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
        {
            return (environ[i] + name_len + 1);
        }
    }
    return (NULL);
}

