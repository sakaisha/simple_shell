#include "main.h"

int _strcmp(char *str_1, char *str_2)
{
    while ((*str_1 != '\0') && (*str_1 == *str_2)) 
	{
        str_1++;
        str_2++;
    }
    if (*str_1 != *str_2) {
        return (*str_1 - *str_2);
    }
    return 0;
}

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

char *_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; (dest[i] = src[i]) != '\0'; i++);
    return dest;
}