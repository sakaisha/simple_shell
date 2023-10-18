#include "main.h"

/**
 * _memset - Entry point
 * Description: Fills memory with a number of bytes
 * @mem: pointer to the memory area
 * @value: value to be filled
 * @n: number of bytes to be filled
 * Return: pointer to the memory area s.
 */
char *_memset(char *mem, char value, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(mem + i) = value;
	return (mem);
}

/**
 * remove_spaces - Entry point
 * Description: Removes spaces from a string
 * @str: Source string.
 * 
 * Return: None.
 */

int remove_spaces(char *str)
{
	int i=0, j=0, flag=0, count=0;

	while (str[i] != '\0')
	{
		while ((str[i]=='\t') || (str[i]==' '))
			i++;
		while ((str[i]!='\0') && (str[i]!=' ') && (str[i]!='\t'))
		{
			flag = 1;
			str[j++] = str[i++];
		}
        if (str[i]!='\0')
			str[j++] = ' ';
		if (flag==1)
		{
			count += 1;
			flag = 0;
		}
	}
	while (str[j]!='\0')
		str[j++] = '\0';
	return (count);
}

/**
 * _strcat - Entry point
 * Description: Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * 
 * Return: A pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i,j;
	short flag=1;

    i=0;
    j=0;
    while (flag)
    {
        if (*(dest+i) == '\0')
		{
            while (*(src+j) != '\0')
            {
                *(dest+i) = *(src+j);
                j=j+1;
                i=i+1;
            }
			*(dest+i) = '\0';
			flag=0;
		}
        i=i+1;
    }
	return (dest);
}

/**
 * SIGINTfunction - Entry point
 * Description: Ignore Ctrl C.
 * @sig_int: The signal number
 * 
 * Return: Nothing.
 */

void SIGINTfunction(int sig_int)
{
	(void)sig_int;
	signal(SIGINT, SIGINTfunction);
	fflush(stdout);
}
