#include <unistd.h>
#include <string.h>

void printPathDirectories()
{
    char *path = _getenv("PATH");
    if (path == NULL)
    {
        char error[] = "Error: PATH environment variable not found\n";
        write(2, error, sizeof(error) - 1);
        _exit(EXIT_FAILURE);
    }

    char buf[1024];
    int len = 0;

    char *token = strtok(path, ":");
    while (token != NULL)
    {
        len = 0;
        int n = (int)strlen(token);
        while (n > 0)
        {
            buf[len++] = '0' + (n % 10);
            n /= 10;
        }

        while (len > 0)
        {
            write(1, buf + (--len), 1);
        }

        write(1, "\n", 1);

        token = strtok(NULL, ":");
    }
}
