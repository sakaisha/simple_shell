#include "main.h"

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

void print_num(int num)
{
    int divisor = 1;

    if (num == 0) {
        _putchar('0');
        return;
    }
    if (num < 0) {
        _putchar('-');
        num = -num;
    }
    while (num / divisor >= 10) {
        divisor *= 10;
    }

    while (divisor != 0) {
        _putchar(num / divisor + '0');
        num %= divisor;
        divisor /= 10;
    }
}

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