#include "main.h"

size_t _strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + _strlen(str + 1));
}

