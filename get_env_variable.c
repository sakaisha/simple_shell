#include <unistd.h>
#include <string.h>

char *_getenv(const char *name)
{
    extern char **environ;

    for (int i = 0; environ[i] != NULL; i++)
    {
        char *env_var = environ[i];
        if (strncmp(env_var, name, strlen(name)) == 0 && env_var[strlen(name)] == '=')
        {
            return env_var + strlen(name) + 1;
        }
    }

    return NULL;
}
