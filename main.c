#include "main.h"

/**
 * execute_command - Execute a command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		char *argv[] = {command, NULL};

		if (execve(command, argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *command;
	size_t len;
	ssize_t read_bytes;

	while (1)
	{
		write(1, "#cisfun$ ", 10);

		command = NULL;
		len = 0;

		read_bytes = getline(&command, &len, stdin);

		if (read_bytes == -1) /* Error or end of file (Ctrl+D) */
		{
			if (feof(stdin)) /* End of file */
			{
				write(1, "\n", 1);
				free(command);
				break;
			}
			else
			{
				perror("getline");
				free(command);
				exit(EXIT_FAILURE);
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

		execute_command(command);

		free(command);
	}

	return 0;
}
