#include <unistd.h>

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    char before[] = "Before execve\n";
    write(1, before, sizeof(before) - 1);

    if (execve(argv[0], argv, NULL) == -1)
    {
        char error[] = "Error:\n";
        write(2, error, sizeof(error) - 1);
    }

    char after[] = "After execve\n";
    write(1, after, sizeof(after) - 1);

    return 0;
}
