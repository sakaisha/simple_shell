#include "main.h"

void executeCommand(char *command);

int main(int argc, char *argv[])
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read_bytes;

    while (1)
    {
        write(1, "#cisfun$ ", 10);

        command = (char *)malloc(BUFF_SIZE);
        if (command == NULL)
        {
            handle_malloc_error();
        }

        read_bytes = getline(&command, &len, stdin);

        if (read_bytes == -1)
        {
            if (feof(stdin))
            {
                write(1, "\n", 1);
                free(command);
                break;
            }
            else if (ferror(stdin))
            {
                handle_getline_error();
                free(command);
                continue;
            }
        }

        if (command[read_bytes - 1] == '\n')
        {
            command[read_bytes - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0)
        {
            free(command);
            break;
        }

        executeCommand(command);

        free(command);
    }

    return 0;
}

void executeCommand(char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        handle_fork_error();
    }
    else if (pid == 0)
    {
        char *const envp[] = {NULL};

        if (access(command, X_OK) == -1)
        {
            handle_access_error(command);
            exit(EXIT_FAILURE);
        }

        if (execve(command, (char *const[]) {command, NULL}, environ) == -1);
        {
            handle_execve_error(command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            handle_waitpid_error();
        }
    }
}

