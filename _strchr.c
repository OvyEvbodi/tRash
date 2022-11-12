#include "main.h"

/**
 * _strchr - locates a character in a string
 *
 * @s: the string to scan
 * @c: the character to search for
 *
 * Return: a pointer to the first occurence of c
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

