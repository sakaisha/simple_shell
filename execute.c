#include "main.h"

/**
 * execute - Entry point
 * Description: Execute's program. All programs located in
 * /bin/ /usr/bin, and the functions cd, exit, env.
 * @buffer: String buffer
 * @ch_count: Count of characters in buffer
 * @name: Name of the program
 * @current_path: The current path
 * @loops_count: Count of times the loop has been executed
 * @env: The enviornment variable
 * 
 * Return: 0 if nothing found. 1 if found. 2 if built-in.
 */

int execute(char *buffer, int ch_count, char *name, char *current_path, int loops_count, char **env)
{
	pid_t child_pid;
	char **av = NULL;
	char func[120] = {'\0'};
	int result;
	int n = remove_spaces(buffer);

	if (ch_count == -1)
		return (1);
	av = malloc(sizeof(char *) * (n + 1));
	if (av == NULL)
		return (1);
	split_string(buffer, av, ch_count);
	result = builtin_check(av, current_path, env, name, loops_count);
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
	else if (child_pid == 0)
	{
		if (execve(func, av, NULL) == -1)
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
	}
	else
		wait(NULL);
	free(av);
	return (0);
}
