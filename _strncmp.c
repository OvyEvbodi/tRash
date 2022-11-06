#include "main.h"

/**
 * _strcmp - Compares two strings up to n bytes.
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

