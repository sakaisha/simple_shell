#include "main.h"

/**
 * _strcat - Concatenate a string from source to destination.
 * @dest: Destination string.
 * @src: Source string.
 * Return: A pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
    int i, j;
    int bool = 1;

    for (i = 0; bool == 1; i++)
    {
        if (*(dest + i) == '\0')
        {
            for (j = 0; *(src + j) != '\0'; j++, i++)
                *(dest + i) = *(src + j);
            *(dest + i) = '\0';
            bool = 0;
        }
    }
    return dest;
}

/**
 * _strcpy - Copy a string to another string.
 * @dest: Str is to be printed after copying.
 * @src: Source of string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; *(src + i) != '\0'; i++)
        *(dest + i) = *(src + i);
    *(dest + i) = '\0';
    return dest;
}

/**
 * _strcmp - Compare 2 strings, character by character.
 * @s1: First string to be compared.
 * @s2: Second string for comparing.
 * Return: Equal? 0 : ASCII dif value for the 1st dif numbers.
 */
int _strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; *(s1 + i) != '\0'; i++)
    {
        if (*(s1 + i) != *(s2 + i))
            return (*(s1 + i) - *(s2 + i));
    }
    if (*(s2 + i) != '\0')
        return (*(s2 + i) * -1);
    return 0;
}

/**
 * _stoi - Converts a string number to an integer.
 * @s: The string to be converted to an integer.
 * Return: Number as an integer type.
 */
long _stoi(char *s)
{
    long n = 0, i = 0;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] > '9' || s[i] < '0')
            return -1;
        n = n * 10 + (s[i] - '0');
    }
    return n;
}