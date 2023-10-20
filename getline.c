#include "main.h"

/**
 * _getline_trial - trial to implement getline
 * @buff: Pointer to the buffer
 * @n: Pointer to the size of the buffer
 * @stream: Pointer to the stream.
 *
 * Return: Number of characters read (including newline), or -1 on failure.
 */
ssize_t _getline_trial(char **buff, size_t *n, FILE *stream)
{
	size_t pos = 0;
	char c;
	int ignore_line = 0;
	int word_started = 0;

	if (buff == NULL || n == NULL)
		return (-1);

	if (*buff == NULL || *n == 0)
	{
		*n = 128;
		*buff = (char *)malloc(*n);
		if (*buff == NULL)
			return (-1);
	}
	while (read_char_from_stream(&c, stream) > 0)
	{
		ssize_t result = build_buffer(buff, n, c, &pos, &ignore_line, &word_started);

		if (result == 1)
			break;
		if (result == -1)
			return (-1);
	}
	if (pos == 0)
		return (-1);

	(*buff)[pos] = '\0';
	return ((ssize_t)pos);
}

/**
 * build_buffer - Processes characters and builds the buffer.
 * @buff: Pointer to the buffer.
 * @n: Pointer to the buffer size.
 * @c: Current character.
 * @pos: Pointer to the current position in the buffer.
 * @ignore_line: Pointer to the flag indicating whether to ignore the line.
 * @word_started: Pointer to the flag indicating whether a word has started.
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t build_buffer(char **buff, size_t *n, char c,
		size_t *pos, int *ignore_line, int *word_started)
{
	size_t i;

	if (!(*ignore_line))
	{
		if (*pos + 1 >= *n)
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
		(*buff)[(*pos)++] = c;
	}

	if (c == ' ')
		*word_started = 0;
	else if (c == '#')
	{
		if (!(*word_started))
			*ignore_line = 1;
	}
	else
		*word_started = 1;

	if (c == '\n')
	{
		*ignore_line = 0;
		return (1);
	}
	return (0);
}

/**
 * read_char_from_stream - Reads a character from the stream.
 * @c: Pointer to store the read character.
 * @stream: File stream.
 *
 * Return: 0 on success, -1 on failure
 */
ssize_t read_char_from_stream(char *c, FILE *stream)
{
	int fd = _fileno(stream);

	return (read(fd, c, 1));
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
