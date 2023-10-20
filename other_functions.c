#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @env: Pointer to the array of environment variables.
 * @name: Name of the environment variable to find.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if the variable is not found.
 */
char *_getenv(char **env, const char *name)
{
	while (*env)
	{
		int i = 0;

		while (env[0][i] == name[i])
			i++;
		if (name[i] == '\0' && env[0][i] == '=')
			return (&env[0][i + 1]);
		env++;
	}
	return (NULL);
}

/**
 * builtin_check - Check if a command is a built-in command and execute.
 * @av: Array of strings containing the command and its arguments.
 * @env: Pointer to the array of environment variables.
 *
 * Return: 1 if the command is a built-in and is executed, 0 otherwise.
 */
int builtin_check(char **av, char **env)
{
	long i;

	i = 0;
	if (_strcmp(av[0], "env") == 0)
	{
		i = 0;
		while (env[i])
		{
			write(1, env[i], string_length(env[i]));
			write(1, "\n", 1);
			i = i + 1;
		}
		free(av);
		return (1);
	}
	if (_strcmp(av[0], "exit") == 0)
	{
		free(av[0]);
		free(av);
		exit(2);
	}
	return (0);
}

/**
 * check_argv - Check if a command is in the PATH and update command
 * @av_0: Original command to check.
 * @actual_command: Buffer to store the updated command.
 * @env: Pointer to the array of environment variables.
 *
 * Return: 1 if the command is found in the PATH, 0 otherwise.
 */
int check_argv(char *av_0, char *actual_command, char **env)
{
	int i, j;
	struct stat status;
	char *str = NULL;

	i = 0;
	j = 0;

	if (stat(av_0, &status) == 0)
	{
		_strcpy(actual_command, av_0);
		return (1);
	}
	str = _getenv(env, "PATH");
	while (str[i] != '\0')
	{
		if (str[i] == ':' || str[i] == '\0')
		{
			actual_command[j] = '/';
			j++;
			_strcat(actual_command, av_0);
			if (access(actual_command, 1) == 0)
				return (1);
			_memset(actual_command, 0, string_length(actual_command));
			j = 0;
		}
		else
		{
			actual_command[j] = str[i];
			j++;
		}
		i++;
	}
	return (0);
}

