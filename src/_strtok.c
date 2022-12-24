#include "../include/tRash.h"

/**
 * _strtok_and_cmnt - tokenizes a string and skips comments
 * @str: the string to tokenize
 * @delim: the delimiter to split the string with
 *
 * Return: a pointer to the current token
 */

char *_strtok_and_cmnt(char *str, const char *delim)
{
	char *token;
	static char *next_token, *end_of_string;
	size_t ind, flag = NO_VALID_CHAR;

	if (str)
	{
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
		/* for handling comments */
		if (*next_token == '#' && (token == next_token || !*(next_token - 1)))
		{
			*next_token = '\0';
			return (token);
		}
		for (ind = 0; delim[ind]; ind++)
		{
			if (delim[ind] == *next_token)
			{
				*next_token = '\0';
				if (next_token == token)
					token++;
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
