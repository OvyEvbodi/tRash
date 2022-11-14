#include "main.h"

/**
 * _strlen - counts the characters in a string
 * @str: the string to count
 *
 * Return: the number of characters in a string
 */

size_t _strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + _strlen(str + 1));
}

