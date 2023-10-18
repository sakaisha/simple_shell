#include "main.h"

/**
 * _memset - Entry point
 * Description: Fills the first n bytes of the memory area.
 * @s: String that needs to be filled.
 * @b: Constant byte b that will fill the memory area.
 * @n: Number of bytes to be filled.
 *
 * Return: Pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        *(s + i) = b;
    return (s);
}

/**
 * handle_sigint - Entry point
 * Description: Handle ignore when user hits Ctrl+C.
 * @sig_num: Number 2 when hitting Ctrl+C.
 * Return: Nothing.
 */
void handle_sigint(int sig_num)
{
    (void)sig_num;
    signal(SIGINT, handle_sigint);
    fflush(stdout);
}

/**
 * release_memory - Entry point
 * Description: A simple function to free memory, used in
 * our builtin function.
 * @av: The buffer to free.
 * Return: None.
 */
void release_memory(char **av)
{
    free(av[0]);
    free(av);
}