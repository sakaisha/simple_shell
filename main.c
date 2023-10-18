#include "main.h"

/**
 * main - Entry point
 * Description: Entry point for our shell. Prompts user for input and decides
 * how to handle the incoming commands.
 * @argc: The count of arguments passed.
 * @argv: The arguments passed.
 * @env: Gets the environment.
 * Return: 0 upon successful completion.
 */

int main(int argc, char **argv, char **env)
{
    char *buffer = NULL, prev_directory[200];
    int rd = 0, ct = 0, result = 0; 
    size_t size = 0;
    int i = 0, status = 1, check;
    char *name = argv[0];

    (void)argc;
    _memset(prev_directory, 0, 200);
    _strcpy(prev_directory, _getenv(env, "PWD"));
    signal(SIGINT, handle_sigint);

    while (status)
    {
        ct++;
        check = 0;
        if (isatty(0) == 1)
            write(STDOUT_FILENO, "$ ", 2);
        rd = getline(&buffer, &size, stdin);
        for (i = 0; buffer[i] != '\0'; i++)
        {
            if (buffer[i] == ' ' || buffer[i] == '\t')
                check++;
        }
        if (rd == 1 || rd == check + 1)
            continue;
        else if (rd == -1)
        {
            status = 0;
            if (result == 2) 
            {
                if (buffer)
                    free(buffer);
                write(1, "\n", 1);
                exit(2);
            }
        }
        else
            result = execute_program(buffer, rd, name, prev_directory, ct, env); 
    }
    if (buffer)
        free(buffer);
    if (isatty(0) == 1)
        write(1, "\n", 1);
    return 0;
}