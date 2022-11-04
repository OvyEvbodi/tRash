#include "main.h"


char *reline(ssize_t *len)
{
	char *line = NULL;
        ssize_t leng = 0;
	//printf("%s from reline\n", line);
	*len = _getline(&line, &leng, STDIN_FILENO);
	if (*len == EOF)
	 	exit(EXIT_SUCCESS);
	//printf("%s after, from reline\n", line);
	return (line);
}

int main(void)
{
	ssize_t line_len = 0;
	ssize_t *len = &line_len;
	char *line;
	char *cwd = NULL;
	short slash = 2;

	/*cruise, lol*/
	cwd = getcwd(cwd, 0);
	while(slash)
	{
		if (*cwd == '/')
			cwd++;
		while (*cwd != '/')
			cwd++;
		slash--;
	}
	cwd++;

	do {
		dprintf(STDERR_FILENO, "Trash :%s (%s)\n$$>> ", cwd, __DATE__);
		line = reline(len);
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		printf("your eff'd up line--> %s\n", line);
		line = NULL;
		free(line);

 	} while (line_len > 0);
	free(cwd);

	return (0);
	
}
