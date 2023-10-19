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
		exit(0);
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