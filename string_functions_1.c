#include "main.h"

char *_memset(char *mem, char value, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(mem + i) = value;
	return (mem);
}

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

void SIGINTfunction(int sig_int)
{
	(void)sig_int;
	signal(SIGINT, SIGINTfunction);
	fflush(stdout);
}
