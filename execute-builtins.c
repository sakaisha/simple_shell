#include "main.h"

/**
 * execute_program - Entry point
 * Description: Executes a program. All programs located in
 * /bin/ /usr/bin, and the functions cd, exit, env.
 * @buf: A string of arguments.
 * @rd: Number of characters read.
 * @name: The name of the program, from argv[0].
 * @p_cwd: Name of the previous working directory.
 * @ct: Count of times the loop has been executed.
 * @env: The environment variable.
 * Return: Returns 0 on success. 1 if there's an error.
 */

int execute_program(char *buf, int rd, char *name, char *p_cwd, int ct, char **env)
{
    char f_av[100] = {'\0'};
    char **av = NULL;
    pid_t child_pid;
    int n = split_string(buf, av, rd);
    int built_in_ret;

    if (rd == -1)
        return (1);
    av = malloc(sizeof(char *) * (n + 1));
    if (av == NULL)
        return (1);
    split_string(buf, av, rd);
    /* check if local program or other built-in func*/

    built_in_ret = handle_builtin(av, p_cwd, env, name, ct);
    if (built_in_ret == 1)
        return (0);
    else if (built_in_ret == 2)
        return (2);
    /* check if the command located in PATH */
    _strcpy(f_av, av[0]);
    if (check_argv(name, f_av, env) == 0)
    {
        write(STDERR_FILENO, name, _strlen(name));
        write(STDERR_FILENO, ": ", 2);
        print_number(ct);
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, av[0], _strlen(av[0]));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, "not found\n", 10);
        return (127);
    }
    child_pid = fork();

    if (child_pid == -1)
    {
        free(av);
        perror("fork Error:");
        return (1);
    }
    else if (child_pid == 0)
    {
        if (execve(f_av, av, NULL) == -1)
        {
            write(STDERR_FILENO, name, _strlen(name));
            write(STDERR_FILENO, ": ", 2);
            print_number(ct);
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, av[0], _strlen(av[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, "not found\n", 10);
            free(av);
            exit(0);
        }
    }
    else
        wait(NULL);
    free(av);
    return (0);
}
