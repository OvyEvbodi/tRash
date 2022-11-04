#include "main.h"

/**
 * _getline - reads a line from the standard input
 *
 * @line_buff: a pointer to the input string
 * @capacity: the length of characters to be read
 * @stream: the stream to read from
 *
 * Return: the number of characters read into line_buff,
 * otherwise, -1 if the end-of-file is reached.
*/

ssize_t _getline(char **line_buff, ssize_t *capacity, size_t stream)
{
	ssize_t position = 0;

	/*allocate mem only when needed*/
	if (!(*line_buff))
	{
		//*line_buff = "here";
		//printf("%s from get\n", *line_buff);
		*line_buff = malloc(sizeof(char) * (*capacity));
		//*line_buff = "memset";
		//printf("%s from get\n", *line_buff);
		if (!(*line_buff))
		{
			perror("Error allocating memory");
			/*what should we return?*/
			exit(EXIT_FAILURE);
		}
	}
	if ((*capacity) <= 0)
		*capacity = BUFSIZ;

	do {
		/*reallocate mem when needed*/
		if (position == (*capacity))
		{
			*line_buff = _realloc(*line_buff, *capacity, (*capacity + BUFSIZ));
			*capacity += BUFSIZ;
			if (!line_buff)
			{
				perror("Error reallocating memory");
				/*what should we return?*/
				exit(EXIT_FAILURE);
			}
		}
		
		position = read(stream, *line_buff, *capacity);
		if (position == -1)
		{
			perror("Error reading input\n");
			exit(EXIT_FAILURE);
		}
		//printf("%s after read call\n", *line_buff);
		/*how to check if EOF is reached*/
		if (position == 0 || _strcmp(*line_buff, "exit\n") == 0)
			return (EOF);

		//I'm trying to take a different approach
		//position = write(fd, *line_buff, position);
	} while (position == *capacity);

	return (position);
	/*NOTE: caller frees line_buff*/
}
