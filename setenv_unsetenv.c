#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    char name[] = "MY_VARIABLE";
    char value[] = "my_value";

    char setting[] = "Setting environment variable: ";
    write(1, setting, sizeof(setting) - 1);
    write(1, name, sizeof(name) - 1);
    write(1, "=", 1);
    write(1, value, sizeof(value) - 1);
    write(1, "\n", 1);

    _setenv(name, value, 1);

    char *result = _getenv(name);
    char retrieved[] = "Retrieved value: ";
    write(1, retrieved, sizeof(retrieved) - 1);
    write(1, result, strlen(result));
    write(1, "\n", 1);

    char unsetting[] = "Unsetting environment variable: ";
    write(1, unsetting, sizeof(unsetting) - 1);
    write(1, name, sizeof(name) - 1);
    write(1, "\n", 1);

    _unsetenv(name);

    result = _getenv(name);
    if (result == NULL)
    {
        char success[] = "Variable unset successfully\n";
        write(1, success, sizeof(success) - 1);
    }
    else
    {
        char still_present[] = "Error: Variable still present\n";
        write(2, still_present, sizeof(still_present) - 1);
    }

    return 0;
}
