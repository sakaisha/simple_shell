#include "main.h"

/**
 * _strcmp - Compare two strings
 * @str_1: The first string
 * @str_2: The second string
 *
 * Return: 0 if strings are equal, positive if str_1 is greater,
 *         negative if str_2 is greater
 */
int _strcmp(char *str_1, char *str_2)
{
	while ((*str_1 != '\0') && (*str_1 == *str_2))
	{
		str_1++;
		str_2++;
	}
	if (*str_1 != *str_2)
	{
		return (*str_1 - *str_2);
	}
	return (0);
}

/**
 * print_num - Print an integer
 * @num: The integer to be printed
 */
void print_num(int num)
{
	int divisor = 1;

	while (num / divisor >= 10)
		divisor *= 10;
	while (divisor != 0)
	{
		_putchar(num / divisor + '0');
		num %= divisor;
		divisor /= 10;
	}
}

/**
 * _strcpy - Copy a string
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; (dest[i] = src[i]) != '\0'; i++)
		;

	return (dest);
}

/**
 * string_to_integer - Convert a string to an integer
 * @str: The string to be converted
 *
 * Return: The integer value of the string
 * -1 if the string is not a number
 */
long string_to_integer(char *str)
{
	long num = 0, i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		num = num * 10 + (str[i] - '0');
	}
	return (num);
}

