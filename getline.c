#include "main.h"
/**
 * _getline_trial - trial to implement getline
 * @buff: Pointer to the buffer
 * @n: Pointer to the size of the buffer
 * @stream: Pointer to the stream.
 * Return: Number of characters read (including newline), or -1 on failure.
 */
ssize_t _getline_trial(char **buff, size_t *n, FILE *stream)
{
	size_t pos = 0, i = 0;
	char c;
	int fd = _fileno(stream);

	if (buff == NULL || n == NULL)
		return (-1);

	if (*buff == NULL || *n == 0)
	{
		*n = 128;
		*buff = (char *)malloc(*n);
		if (*buff == NULL)
			return (-1);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (pos + 1 >= *n)
		{
			size_t new_size = *n * 2;
			char *new_buff = (char *)malloc(new_size);

			if (new_buff == NULL)
				return (-1);
			for (i = 0; i < *n; ++i)
				new_buff[i] = (*buff)[i];
			free(*buff);
			*buff = new_buff;
			*n = new_size;
		}
		(*buff)[pos++] = c;
		if (c == '\n')
			break;
	}
	if (pos == 0)
		return (-1);
	(*buff)[pos] = '\0';
	return ((ssize_t) pos);
}

/**
 * _fileno - Gets the file descriptor associated.
 * @stream: FILE stream.
 *
 * Return: The file descriptor, or -1 if the stream is NULL
 */
int _fileno(FILE *stream)
{
	if (!stream)
		return (-1);
	return (stream->_fileno);
}

