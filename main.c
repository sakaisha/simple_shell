#include "main.h"

/**
 * main - Entry point for the shell program
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @env: Array of environment variables
 * Return: Always 0 (success)
 */
int main(int argc, char **argv, char **env)
{
	char dir[250];
	char *buff = NULL;
	size_t size;
	ssize_t line_st;
	int count;
	int spaces;
	int i;
	char *name;
	int execute_return;

	execute_return = 1;
	i = 0;
	size = 0;
	line_st = 0;
	count = 0;
	spaces = 0;
	name = argv[0];
	(void) argc;
	_memset(dir, 0, 250);
	_strcpy(dir, _getenv(env, "PWD"));
	signal(2, SIGINTfunction);

	while (1)
	{
		if (execute_return != -1)
		{
			if (isatty(0) == 1)
				write(1, ":)  ", 3);
			spaces = 0;

			line_st = getline(&buff, &size, stdin);
			count++;

			if (line_st == 1)
				continue;

			while (buff[i] != '\0')
			{
				if (buff[i] == '\n')
					spaces++;
				else if (buff[i] == '\r')
					spaces++;
				else if (buff[i] == '\t')
					spaces++;
				else if (buff[i] == ' ')
					spaces++;
				i = i + 1;
			}

			if ((line_st == -1) && (spaces == 2))
			{
				if (buff)
					free(buff);
				write(1, "\n", 1);
				exit(2);
				break;
			}
			else if ((line_st == -1) && (spaces != 2))
			{
				break;
			}
			else
				execute_return = execute(buff, line_st, name, count, env);
		}
	}
	if (buff)
		free(buff);
	if (isatty(0) == 1)
		write(1, "\n", 1);
	return (0);
}

/**
 * execute - Execute a command
 * @buff: Input buffer
 * @line_st: Length of input line
 * @name: Name of the shell program
 * @loops_count: Number of loops executed
 * @env: Array of environment variables
 * Return: 0 on success, 1 on failure
 */
int execute(char *buff, int line_st, char *name, int loops_count, char **env)
{
	pid_t child_pid;
	char **av = NULL;
	char func[200] = {'\0'};
	int result;
	int n = remove_spaces(buff);

	if (buff[0] == '\0')
		return (1);

	if (line_st == -1)
		return (1);

	av = malloc(sizeof(char *) * (n + 1));

	if (av == NULL)
		return (1);

	split_string(buff, av, line_st);

	result = builtin_check(av, env);

	if (result == 1)
		return (0);
	else if (result == 2)
		return (2);

	_strcpy(func, av[0]);

	if (check_argv(av[0], func, env) == 0)
	{
		write(2, name, string_length(name));
		write(2, ": ", 2);
		print_num(loops_count);
		write(2, ": ", 2);
		write(2, av[0], string_length(av[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		return (127);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		free(av);
		perror("fork Error:");
		return (1);
	}
	else if ((child_pid == 0) && (execve(func, av, NULL) == -1))
	{
		write(2, name, string_length(name));
		write(2, ": ", 2);
		print_num(loops_count);
		write(2, ": ", 2);
		write(2, av[0], string_length(av[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		free(av);
		exit(0);
	}
	else
		wait(NULL);
	free(av);
	return (0);
}
