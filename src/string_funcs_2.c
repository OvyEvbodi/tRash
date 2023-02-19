#include "../include/tRash.h"

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

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}

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
