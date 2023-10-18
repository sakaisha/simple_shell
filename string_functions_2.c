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