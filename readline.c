#include "main.h"

int main(void)
{
	ssize_t line_len = 0;
	ssize_t *len = &line_len;

	do {
		printf("fucking trash $$>> ");
		char *line = reline(len);
		printf("your eff'd up line--> %s\n", line);
		free(line);
	} while (line_len > 0);
	
}

char *reline(ssize_t *line_len)
{
	char *line = NULL;
        size_t leng = 0;

	*line_len = getline(&line, &leng, STDIN_FILENO);
	return (line);
}

