#include "main.h"

/**
 * _strdup - Allocates space in memory, fills with the copy of a given string.
 * @str: String for which copy should be used to fill allocated memory.
 *
 * Return: Returns pointer to duplicate string, NULL if insufficient memory,
 * NULL if str=NULL.
 */
char *_strdup(char *str)
{
	char *mptr;
	unsigned int i, size;

	if (str == NULL)
		return (NULL);

	for (size = 0; *(str + size); size++)
		;

	mptr = (char *)malloc(sizeof(char) * size + 1);
	if (mptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(mptr + i) = *(str + i);
	*(mptr + i) = '\0';

	return (mptr);
}

