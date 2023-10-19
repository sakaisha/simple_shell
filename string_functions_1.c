#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s
 *           with the constant byte c.
 * @s: Pointer to the memory area.
 * @c: Constant byte to fill the memory with.
 * @n: Number of bytes to fill.
 *
 * Return: Pointer to the filled memory area @s.
 */
char *_memset(char *s, char c, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = c;
		n--;
	}
	return (s);
}

/**
 * remove_spaces - Removes extra spaces and tabs from a string in-place.
 * @str: String to be modified.
 *
 * Return: Number of spaces removed.
 */
int remove_spaces(char *str)
{
	int i = 0, j = 0, count = 0;
	int flag = 0;
	int k = 0;
	int length = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			flag = 0;
		else
		{
			if (!flag)
			{
				if (count > 0)
				{
					str[j++] = ' ';
				}
				flag = 1;
				count++;
			}
			str[j++] = str[i];
		}
		i++;
	}
	while (str[j] != '\0')
	{
		str[j++] = '\0';
	}
	length = string_length(str);
    k = length - 1;
    while (k >= 0 && (str[k] == ' ' || str[k] == '\t')) {
        str[k] = '\0';
        k--;
    }
	if (str[k] == '\n' && str[k - 1] == ' ' && k > 0)
	{
		str[k - 1] = '\n';
		str[k] = '\0';
	}
	if (str[0] == '\n')
		str[0] = '\0';
	return (count);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string, should have enough space for the result.
 * @src: Source string to be appended to dest.
 *
 * Return: Pointer to the resulting string (same as dest).
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	short flag = 1;

	i = 0;
	j = 0;
	while (flag)
	{
		if (*(dest + i) == '\0')
		{
			while (*(src + j) != '\0')
			{
				*(dest + i) = *(src + j);
				j = j + 1;
				i = i + 1;
			}
			*(dest + i) = '\0';
			flag = 0;
		}
		i = i + 1;
	}
	return (dest);
}

/**
 * SIGINTfunction - Handles the SIGINT signal (Ctrl+C) by flushing stdout.
 * @sig_int: Signal number (ignored).
 */
void SIGINTfunction(int sig_int)
{
	(void)sig_int;
	signal(SIGINT, SIGINTfunction);
	fflush(stdout);
}

