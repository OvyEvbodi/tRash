#include "main.h"

/**
 * _strcpy - Copies the string from src to dest, including null byte.
 * @dest: Pointer to destination.
 * @src: Pointer to source.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; 1; i++)
	{
		if (src[i] == '\0')
		{
			dest[i] = src[i];
			break;
		}
		else
		{
			dest[i] = src[i];
		}
	}
	return (dest);
}

