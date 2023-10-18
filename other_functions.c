#include "main.h"

/**
 * _getenv - Entry point
 * Description: Get the value of environment
 * @env: The environment variable
 * @name: Name of environment
 * 
 * Return: String of value of environment.
 */

char *_getenv(char **env, const char *name)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (name[length] != '\0')
		length++;
	while (env[i])
	{
		while (env[i][j] == name[j])
			j = j + 1;
		if (j==length)
			return (&env[i][length+1]);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - Entry point
 * Description: Get the value of environment
 * @env: The environment variable
 * @name: Name of environment
 * @value: String of the value
 * @overwrite: Determines when to overwrite
 * 
 * Return: String of value of environment
 */

int _setenv(char **env, const char *name, const char *value, int overwrite)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (name[length] != '\0')
		length++;
	while (env[i] && overwrite > 0)
	{
		while (env[i][j] == name[j])
			j = j + 1;
		if (j == length)
		{
			env[i][length] = '=';
			for (j = 0; value[j] != '\0'; j++)
				env[i][length + j + 1] = value[j];
			env[i][length + j + 1] = '\0';
			break;
		}
		i++;
	}
	return (0);
}

/**
 * builtin_check - Entry point
 * Description: Checks if the command is a built-in
 * @av: Arguments
 * @prev_directory: The previous directory
 * @env: The environment variable
 * @name: The name of the program
 * @loop_count: count of times the loop has been executed
 * 
 * Return: 0 if nothing found. 1 if found. 2 if built-in.
 */

int builtin_check(char **av, char *prev_directory, char **env, char *name, int loop_count)
{
	long i;
	int value;
	
	i = 0;
	value = 0;
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
		exit(0);
	}
	if (_strcmp(av[0], "cd") == 0)
	{
		value = change_directory(av[1], prev_directory, env, name, loop_count, av);
		free(av);
		if (value == 2)
			return (2);
		return (1);
	}
	return (0);
}

/**
 * check_argv - Entry point
 * Description: Checks if the command exists in PATH
 * @av_0: The name of the command
 * @actual_command: The full path of the command
 * @env: The environment variable
 * 
 * Return: 0 if nothing found.
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
		actual_command = av_0;
		return (1);
	}

	str = _getenv(env, "PATH");
	do {
		if (str[i] == '\0' || str[i] == ':')
		{
			_strcat(actual_command, "/");
			_strcat(actual_command, av_0);
			if (access(actual_command, 1) == 0)
				return (1);
			_memset(actual_command, 0, string_length(actual_command));
			j = 0;
		}
		else
		{
			*(actual_command + j) = str[i];
			j++;
		}
	} while (str[i++] != '\0');
	
	return (0);
}

/**
 * change_directory - Entry point
 * @av_2: The second argument
 * @current_path: The current directory
 * @env: The enviornment variable
 * @name: The name of the program
 * @loops_count: The count of loops
 * @av: The argument string
 * 
 * Return: Returns a pointer to the updated directory.
 */

int change_directory(char *av_2, char *current_path, char **env, char *name, int loops_count, char **av)
{
	char str[250];
	char *tmp;

	_strcpy(str, _getenv(env, "HOME"));
	tmp = getcwd(NULL, 200);
	if ((_strcmp(av_2, "$HOME") == 0) || (av_2 == NULL))
	{
		chdir(str);
		_memset(current_path, 0, 250);
		_strcpy(current_path, tmp);
		free(tmp);
		_setenv(env, "PWD", str, 1);
		return (0);
	}
	else
	{
		write(2, name, string_length(name));
		write(2, ": ", 2);
		print_num(loops_count);
		write(2, ": ", 2);
		write(2, av[0], string_length(av[0]));
		write(2, ": can't cd to ", 15);
		write(2, av[1], string_length(av[1]));
		write(2, "\n", 1);
		free(tmp);
		return (2);
	}
}
