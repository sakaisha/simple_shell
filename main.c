#include "main.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * @env: Array of environment variables.
 * Return: Always 0 (success).
 */
int main(int argc, char **argv, char **env)
{
	char dir[BUFFER_SIZE], *buff = NULL, *name = argv[0];
	size_t size = 0;
	ssize_t line_st;
	int count = 0, spaces;

	(void)argc;
	_memset(dir, 0, BUFFER_SIZE);
	_strcpy(dir, _getenv(env, "PWD"));
	signal(2, SIGINTfunction);

	while ((handle_prompt(), line_st = getline(&buff, &size, stdin)) != -1)
	{
		count++;

		if (line_st == 1)
			continue;

		spaces = count_spaces(buff);

		if ((line_st == -1) && (spaces == 2))
			handle_eof(buff);
		else if ((line_st == -1) && (spaces != 2))
			break;

		execute(buff, line_st, name, count, env);
	}

	if (buff)
		free(buff);

	handle_newline();
	return (0);
}



/**
 * handle_prompt - Display the shell prompt.
 */
void handle_prompt(void)
{
	if (isatty(0) == 1)
		write(1, ":)  ", 3);
}

/**
 * count_spaces - Count the number of spaces in a string.
 * @str: The input string.
 * Return: The number of spaces.
 */
int count_spaces(char *str)
{
	int spaces = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == ' ')
			spaces++;
		i++;
	}

	return (spaces);
}

/**
 * handle_eof - Handle end-of-file scenario.
 * @buff: Input buffer.
 */
void handle_eof(char *buff)
{
	if (buff)
		free(buff);

	write(1, "\n", 1);
	exit(2);
}

/**
 * handle_newline - Handle the newline character.
 */
void handle_newline(void)
{
	if (isatty(0) == 1)
		write(1, "\n", 1);
}




