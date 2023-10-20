#include "main.h"

/**
 * execute - Execute a command.
 * @buff: Input buffer.
 * @line_st: Length of input line.
 * @name: Name of the shell program.
 * @loops_count: Number of loops executed.
 * @env: Array of environment variables.
 * Return: 0 on success, 1 on failure.
 */
int execute(char *buff, int line_st, char *name, int loops_count, char **env)
{
	char **av = NULL;
	char func[BUFFER_SIZE] = {'\0'};
	int result;

	if (prepare_execution(buff, line_st, name, loops_count,
				env, &av, func, &result) != 0)
		return (result);

	if (execute_command(av, func, name, loops_count) != 0)
		return (1);

	free(av);
	return (0);
}

/**
 * prepare_execution - Prepare for command execution.
 * @buff: Input buffer.
 * @line_st: Length of input line.
 * @name: Name of the shell program.
 * @loops_count: Number of loops executed.
 * @env: Array of environment variables.
 * @av: Pointer to the array of command arguments.
 * @func: Buffer to store the command.
 * @result: Pointer to store the result of the preparation.
 * Return: 0 on success, error code on failure.
 */
int prepare_execution(char *buff, int line_st, char *name, int loops_count,
		char **env, char ***av, char *func, int *result)
{
	int n = remove_spaces(buff);

	if (buff[0] == '\0')
		return (1);

	if (line_st == -1)
		return (2);

	*av = malloc(sizeof(char *) * (n + 1));

	if (*av == NULL)
		return (3);

	split_string(buff, *av, line_st);

	*result = builtin_check(*av, env, loops_count);

	if (*result == 1 || *result == 2)
	{
		return (4);
	}

	_strcpy(func, (*av)[0]);

	if (check_argv((*av)[0], func, env) == 0)
	{
		handle_command_not_found(*av, name, loops_count);
		free(*av);
		return (5);
	}

	return (0);
}

/**
 * execute_command - Execute the prepared command.
 * @av: Array of command arguments.
 * @func: Buffer containing the command.
 * @name: Name of the shell program.
 * @loops_count: Number of loops executed.
 * Return: 0 on success, 1 on failure.
 */
int execute_command(char **av, char *func, char *name, int loops_count)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		free(av);
		perror("fork Error:");
		return 1;
	}
	else if (child_pid == 0)
	{
		if (execve(func, av, NULL) == -1)
		{
			handle_command_not_found(av, name, loops_count);
			free(av);
			_exit(0);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid Error:");
			free(av);
			return 1;
		}
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			free(av);
			return exit_status;
		}
		else
		{
			free(av);
			return 1;
		}
	}
	return 0;
}

/**
 * handle_command_not_found - Handle command not found error.
 * @av: Array of command arguments.
 * @name: Name of the shell program.
 * @loops_count: Number of loops executed.
 */
void handle_command_not_found(char **av, char *name, int loops_count)
{
	write(2, name, string_length(name));
	write(2, ": ", 2);
	print_num(loops_count);
	write(2, ": ", 2);
	write(2, av[0], string_length(av[0]));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}




