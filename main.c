#include "main.h"
#include "sorry-error.h"

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
            else
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
                // Check if the command is valid
                handle_access_error(command);
            }

            if (execve(command, NULL, environ) == -1)
            {
                // Execution failed
                handle_execve_error(command);
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

        free(command);
    }

    return 0;
}
