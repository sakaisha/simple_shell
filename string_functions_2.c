#include "main.h"

/**
 * _strcmp - Entry point
 * Description: Compares two strings
 * @str_1: String 1
 * @str_2: String 2
 * 
 * Return: -1 if str_1 < str_2, 0 if str_1 == str_2, 1 if str_1 > str_2
 */

int _strcmp(char *str_1, char *str_2)
{
	int i;

	i = 0;
	while(*(str_1+i)!='\0')
	{
		if (*(str_1+i) != *(str_2+i))
			return (*(str_1+i) - *(str_2+i));
		i++;
	}
	if (*(str_2+i) != '\0')
		return (*(str_2+i) * -1);
	return (0);
}

/**
 * _stoi - Entry point
 * Description: Converts strings to integers
 * @str: String to be converted
 * 
 * Return: -1 if str is not a number, otherwise the number
 */

long _stoi(char *str)
{
	long n = 0;
	long i = 0;

	while(str[i]!='\0')
	{
		if ((str[i]<'0') || (str[i]>'9'))
			return (-1);
		n = n * 10 + (str[i]-'0');
		i++;
	}
	return (n);
}

/**
 * print_num - Entry point
 * Description: Prints a number
 * @num: Number to be printed
 * 
 * Return: None.
 */

void print_num(int num)
{
	int n = num;
	int tmp = 0;
	int max_num = 1000000000;

	while ((n/max_num) == 0)
		max_num /= 10;
	while (max_num > 0)
	{
		tmp = n/max_num;
		n = n%max_num;
		_putchar(tmp + '0');
		max_num /= 10;
	}
}

/**
 * _strcpy - Entry point
 * Description: copy a string to another string.
 * @dest: Destination string
 * @src: Source string
 * 
 * Return: Pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(*(src + i) != '\0')
	{
		*(dest+i) = *(src+i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}