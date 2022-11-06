#include "main.h"

char *_strtok(char *str, const char *delim)
{
	char *token;
	/* static since we might need to reuse them on the next func call */
	static char *next_token = NULL, *end_of_string = NULL;
	size_t ind, flag = NO_VALID_CHAR;

	if (str)
	{
		/* (re)assign start and end addresses to static variables */
		next_token = str;
		end_of_string = str + _strlen(str);
	}
	if (next_token == end_of_string)
		return (NULL);

	for (token = next_token; *next_token; next_token++)
	{
		if (next_token != token)
			if (*next_token && !*(next_token - 1))
				break;
		for (ind = 0; delim[ind]; ind++)
		{
			if (delim[ind] == *next_token)
			{
				*next_token = '\0';
				if (next_token == token)
					token++; /* in case delims preceed valid chars */
				break;
			}
		}
		if (*next_token)
			flag = VALID_CHAR;
	}
	if (flag == NO_VALID_CHAR)
		return (NULL);

	return (token);
}

