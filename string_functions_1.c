#include "main.h"

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

int remove_spaces(char *str)
{
    int i = 0, j = 0, count = 0;
    int flag = 0;

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
    return count;
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
