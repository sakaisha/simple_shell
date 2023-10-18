#include "main.h"

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
