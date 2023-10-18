#include "main.h"

/**
 * check_argv - Entry point
 * Description: Check status of argument in /bin/ and /usr/bin
 * @av0: First argument from user.
 * @f_av: Pointer to a full path of command.
 * @env: The environment variable.
 * Return: 0 if nothing found.
 */

int check_argv(char *av0, char *f_av, char **env)
{
    struct stat st;
    int i = 0, j = 0;
    char *str = NULL;

    /* handle local functions */
    if (stat(av0, &st) == 0)
    {
        f_av = av0;
        return (1);
    }

    str = getenv(env, "PATH");
    do {
        if (str[i] == ':' || str[i] == '\0')
        {
            _strcat(f_av, "/");
            _strcat(f_av, av0);
            if (access(f_av, X_OK) == 0)
                return (1);
            _memset(f_av, 0, _strlen(f_av));
            j = 0;
        }
        else
            f_av[j++] = str[i];
    } while (str[i++] != '\0');
    return (0);
}

/**
 * handle_builtin - Entry point
 * Description: Check for valid built_in function and run it.
 * @av: The arguments being passed.
 * @prev_directory: The name of the previous working directory.
 * @env: The environment variable.
 * @name: The program name, from argv[0].
 * @count: The count of times the program has looped.
 * Return: 1 if valid, else 0.
 */

int handle_builtin(char **av, char *prev_directory, char **env, char *name, int count)
{
    long i = 0;
    int j = 0, ret_val = 0;

    if (_strcmp(av[0], "cd") == 0)
    {
        ret_val = change_directory(av[1], prev_directory, env, name, count, av);
        release_memory(av);
        if (ret_val == 2)
            return (2);
        return (1);
    }