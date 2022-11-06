#include "main.h"

#define BUFF_SIZE 1024

int _strcpy(char *, char *);

ssize_t __getline(char **line_buff, size_t *capacity, FILE *stream)
{
	ssize_t rd, tot_read = 0, buff_extension = BUFF_SIZE;
	char *tmp_buff, c;

	tmp_buff = malloc(sizeof(char) * BUFF_SIZE);
	if (!tmp_buff)
		return (-1);
	do {
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == -1 || (rd == 0 && tot_read == 0))
		{
			free(tmp_buff);
			return (-1);
		}

		tmp_buff[tot_read++] = c;
		if (tot_read == buff_extension)
		{
			tmp_buff = _realloc(tmp_buff, buff_extension, buff_extension + 1024);
			if (!tmp_buff)
			{
				free(tmp_buff);
				return (-1);
			}
			buff_extension += 1024;
		}
	} while (c != '\n');
	tmp_buff[tot_read] = '\0';

	if (!*line_buff || *capacity < buff_extension)
	{
		*capacity = buff_extension;
		*line_buff = tmp_buff;
		return (tot_read);
	}
	else
	{
		_strcpy(*line_buff, tmp_buff);
		free(tmp_buff);
	}
	return (tot_read);
}

