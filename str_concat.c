#include "main.h"

/**
 * str_concat - Concatenates two strings.
 * @s1: Pointer to first string.
 * @s2: Pointer to second string.
 *
 * Return: Pointer to new memory of concatenated strings. NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *mptr;
	unsigned int i, j, size = 0;

	for (i = 0; s1 && (*(s1 + i)); i++, size++)
		;
	for (i = 0; s2 && (*(s2 + i)); i++, size++)
		;

	mptr = (char *)malloc(sizeof(char) * size + 1);
	if (mptr == NULL)
		return (NULL);

	for (i = 0; s1 && (*(s1 + i)); i++)
		*(mptr + i) = *(s1 + i);

	for (j = 0; s2 && (*(s2 + j)); j++, i++)
		*(mptr + i) = *(s2 + j);

	*(mptr + i) = '\0';

	return (mptr);
}

