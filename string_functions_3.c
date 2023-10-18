#include "main.h"

/**
 * string_length - Entry point
 * @str: Source string
 *
 * Return: The length of the string
 */
int string_length(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

/**
 * _putchar - Entry point
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}


/**
 * split_string - Entry point
 * Description: Splits a string into substrings
 * @buffer: Source string
 * @str_array: Array of substrings
 * @n: Number of characters read
 * 
 * Return: Returns the number of characters counted, - NULL.
 */

int split_string(char *buffer, char **str_array, int n)
{
	int i, j, k;

	i = 0;
	j = 0;
	k = 0;
	for (i = 0; i <= n; i++)
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
		{
			buffer[i] = '\0';
			str_array[k] = &buffer[j];
			j = i + 1;
			k = k + 1;
		}
	}
	if (k == 0)
		str_array[k++] = &buffer[j];
	str_array[k] = NULL;
	return (k);
}



