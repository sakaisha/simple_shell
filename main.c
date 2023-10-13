#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	while (1)
	{
		write(1, "#cisfun$ ", 10);

		char buffer[1024];

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			write(1, "\n", 1);
			break;
		}

		size_t len = strlen(buffer);

		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		write(1, buffer, strlen(buffer));
		write(1, "\n", 1);
	}

	return (0);
}
