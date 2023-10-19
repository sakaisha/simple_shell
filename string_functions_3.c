#include "main.h"

int string_length(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

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



