#include "main.h"

/**
 * string_length - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int string_length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _putchar - Writes a character to the standard error.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * split_string - Splits a string into an array of strings.
 * @str: The input string to be split.
 * @str_array: An array to store the split strings.
 * @n: The maximum number of strings to split.
 *
 * Return: The number of strings obtained after splitting.
 */

int split_string(char *str, char **str_array, int n)
{
	int i, count1, count2;

	i = 0;
	count1 = 0;
	count2 = 0;
	while (i <= n)
	{
		if (str[i] == ' ')
		{
			str[i] = '\0';
			str_array[count2] = &str[count1];
			count1 = i + 1;
			count2 = count2 + 1;
			i++;
		}
		else if (str[i] == '\n')
		{
			str[i] = '\0';
			str_array[count2] = &str[count1];
			count1 = i + 1;
			count2 = count2 + 1;
			i++;
		}
		else
			i++;
	}
	if (count2 == 0)
		str_array[count2++] = &str[count1];
	str_array[count2] = NULL;
	return (count2);
}
