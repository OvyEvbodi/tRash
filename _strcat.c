#include "main.h"

/**
 *_strcat -  appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte
 *
 * @dest: the destination
 * @src: the string to append
 *
 * Return: a pointer to dest
 */

char *_strcat(char *dest, char *src)

{
	int dest_len = 0, src_len = 0, i = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	while (src[src_len] != '\0')
	{
		src_len++;
	}

	while (src_len)
	{
		dest[dest_len] = src[i];
		src_len--;
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';

	return (dest);


}
