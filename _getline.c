#include "main.h"

/**
 * _getline - reads a line from the standard input
 *
 * @line_buff: a pointer to the input string
 * @capacity: the length of characters to be read
 * @fd: file descriptor to read from.
 *
 * Return: the number of characters read into line_buff,
 * otherwise, -1 if the end-of-file is reached.
*/
ssize_t _getline(char **line_buff, size_t *capacity, ssize_t fd)
{
	char *tmp_buff, c;
	ssize_t rd;
	size_t buff_len = BUFF_SIZE, tot_read = 0;

	tmp_buff = malloc(sizeof(char) * BUFF_SIZE);
	if (!tmp_buff)
		perror("Failed to allocate memory."), exit(EXIT_FAILURE);

	do {
		rd = read(fd, &c, 1);
		if (rd == -1 || (rd == 0 && tot_read == 0))
		{
			*line_buff = tmp_buff;
			return (EOF);
		}
		if (rd == 0)
			break;

		tmp_buff[tot_read++] = c;
		if (tot_read == buff_len)
		{
			tmp_buff = _realloc(tmp_buff, buff_len, buff_len + BUFF_SIZE);
			if (!tmp_buff)
				perror("Failed to allocate memory."), exit(EXIT_FAILURE);
			buff_len += BUFF_SIZE;
		}
	} while (c != '\n');

	tmp_buff[tot_read] = '\0';
	if (!*line_buff || *capacity < buff_len)
	{
		*capacity = buff_len;
		*line_buff = tmp_buff;
		return (tot_read);
	}
	_strcpy(*line_buff, tmp_buff);
	free(tmp_buff);

	return (tot_read);
}

