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

/**
 * _strncmp - Compares two strings up to n bytes.
 * @s1: First argument, and string to the be compared to.
 * @s2: Second argument, and string to be compared.
 * @n: Number of bytes to compare.
 *
 * Return: Returns a - number if s1 less than s2, 0 if s1 equal to s2,
 * or a + number if s1 greater than s2.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 || i == n - 1)
			break;
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */

int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ':')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * _strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to the array of words
 */

char **_strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ':' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

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

