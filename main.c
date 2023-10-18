#include "main.h"

/**
 * main - Entry point
 * Description: This is the main function. It handles the simple shell.
 * @argc: The number of arguments
 * @argv: the arguments
 * @env: The enviornment
 * 
 * Return: always 0
 */

int main(int argc, char **argv, char **env)
{
	char prev_directory[250];
	char *buffer = NULL;
	size_t size;
	int line;
	int count; 
	int check;
	int i;
	int status; 
	char *name;

	i = 0;
	status = 1;
	check = 0;
	size = 0;
	line = 0;
	count = 0; 
	check = 0;
	name = argv[0];
	(void) argc;
	_memset(prev_directory, 0, 250);
	_strcpy(prev_directory, _getenv(env, "PWD"));
	signal(2, SIGINTfunction);

	while (status)
	{
		check = 0;
		count++;
		if (isatty(0) == 1)
			write(1, "$ ", 2);
		line = getline(&buffer, &size, stdin);
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\t' || buffer[i] == ' ')
				check++;
			i = i + 1;
		}
		if (line == 1 || line == check + 1)
			continue;
		else if (line == -1)
		{
			status = 0;
			if (check == 2)
			{
				if (buffer)
					free(buffer);
				write(1, "\n", 1);
				exit(2);
			}
		}
		else
			check = execute(buffer, line, name, prev_directory, count, env);
	}
	if (buffer)
		free(buffer);
	if (isatty(0) == 1)
		write(1, "\n", 1);
	return (0);
}
