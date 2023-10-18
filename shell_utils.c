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
        return 1;
    }

    str = getenv(env, "PATH");
    do
    {
        if (str[i] == ':' || str[i] == '\0')
        {
            _strcat(f_av, "/");
            _strcat(f_av, av0);
            if (access(f_av, X_OK) == 0)
                return 1;
            _memset(f_av, 0, _strlen(f_av));
            j = 0;
        }
        else
            f_av[j++] = str[i];
    } while (str[i++] != '\0');
    return 0;
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
            return 2;
        return 1;
    }
    if ((_strcmp(av[0], "exit") == 0) && (av[1] == NULL))
    {
        release_memory(av);
        exit(0);
    }
    else if ((_strcmp(av[0], "exit") == 0) && (av[1] != NULL))
    {
        i = _stoi(av[1]);
        if (i > INT_MAX || i < 0)
        {
            write(STDERR_FILENO, name, _strlen(name));
            write(STDERR_FILENO, ": ", 2);
            print_number(count);
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, av[0], _strlen(av[0]));
            write(STDERR_FILENO, ": Illegal number: ", 18);
            write(STDERR_FILENO, av[1], _strlen(av[1]));
            write(STDERR_FILENO, "\n", 1);
            release_memory(av);
            return 2;
        }
        else if (i >= 0)
        {
            release_memory(av);
            exit(i);
        }
    }
    if (_strcmp(av[0], "env") == 0)
    {
        j = 0;
        while (env[j])
        {
            write(STDOUT_FILENO, env[j], _strlen(env[j]));
            write(STDOUT_FILENO, "\n", 1);
            j++;
        }
        release_memory(av);
        return 1;
    }
    return 0;
}

/**
 * getenv - Entry point
 * Description: Get the value of environment.
 * @env: The environment variable.
 * @name: Name of environment.
 * Return: String of value of environment.
 */

char *getenv(char **env, const char *name)
{
    int i = 0, j = 0, len = 0;

    for (len = 0; name[len] != '\0'; len++)
        ;
    while (env[i])
    {
        for (j = 0; env[i][j] == name[j]; j++)
            ;
        if (j == len)
            return &env[i][len + 1];
        i++;
    }
    return NULL;
}

/**
 * setenv - Entry point
 * Description: Get the value of environment.
 * @env: The environment variable.
 * @name: Name of environment.
 * @value: String of the value.
 * @overwrite: Determines when to overwrite.
 * Return: String of value of environment.
 */

int setenv(char **env, const char *name, const char *value, int overwrite)
{
    int i = 0, j = 0, len = 0;

    for (len = 0; name[len] != '\0'; len++)
        ;
    while (env[i] && overwrite > 0)
    {
        for (j = 0; env[i][j] == name[j]; j++)
            ;
        if (j == len)
        {
            env[i][len] = '=';
            for (j = 0; value[j] != '\0'; j++)
                env[i][len + j + 1] = value[j];
            env[i][len + j + 1] = '\0';
            break;
        }
        i++;
    }
    return 0;
}

/**
 * change_directory - Entry point
 * @av2: The second argument from the user.
 * @pr_cwd: The name of the previous working directory.
 * @env: The environment variable.
 * @name: Char string of argv.
 * @ct: The count of loops.
 * @av: The argument string.
 * Return: Returns a pointer to the updated directory.
 */

int change_directory(char *av2, char *pr_cwd, char **env, char *name, int ct, char **av)
{
    char str[200];
    char *temp;

    _strcpy(str, getenv(env, "HOME"));
    temp = getcwd(NULL, 150);
    if ((av2 == NULL) || (_strcmp(av2, "$HOME") == 0))
    {
        chdir(str);
        _memset(pr_cwd, 0, 200);
        _strcpy(pr_cwd, temp);
        free(temp);
        setenv(env, "PWD", str, 1);
        return 0;
    }
    else if (_strcmp(av2, "-") == 0)
    {
        chdir(pr_cwd);
        write(STDOUT_FILENO, pr_cwd, _strlen(pr_cwd));
        write(STDOUT_FILENO, "\n", 1);
        setenv(env, "PWD", pr_cwd, 1);
        _memset(pr_cwd, 0, 200);
        _strcpy(pr_cwd, temp);
        free(temp);
        return 0;
    }
    else if (chdir(av2) == 0)
    {
        _memset(pr_cwd, 0, 200);
        _strcpy(pr_cwd, temp);
        free(temp);
        _strcat(str, "/");
        _strcat(str, av2);
        setenv(env, "PWD", str, 1);
        return 0;
    }
    else
    {
        write(STDERR_FILENO, name, _strlen(name));
        write(STDERR_FILENO, ": ", 2);
        print_number(ct);
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, av[0], _strlen(av[0]));
        write(STDERR_FILENO, ": can't cd to ", 15);
        write(STDERR_FILENO, av[1], _strlen(av[1]));
        write(STDERR_FILENO, "\n", 1);
        free(temp);
        return 2;
    }
}