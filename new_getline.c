#include "main.h"

ssize_t __getline(char **line_buff, size_t *capacity, FILE *stream)
{
	ssize_t rd, tot_read = 0, buff_len = BUFF_SIZE;
	char *tmp_buff, c;

	tmp_buff = malloc(sizeof(char) * BUFF_SIZE);
	if (!tmp_buff)
		perror("Failed to allocate memory."), exit(EXIT_FAILURE);

	do {
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == -1 || (rd == 0 && tot_read == 0))
		{
			*line_buff = tmp_buff;
			return (EOF);
		}

		tmp_buff[tot_read++] = c;
		if (tot_read == buff_len)
		{
			tmp_buff = _realloc(tmp_buff, buff_len, buff_len + 1024);
			if (!tmp_buff)
				perror("Failed to allocate memory."), exit(EXIT_FAILURE);
			buff_len += 1024;
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

