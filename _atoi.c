/**
 * exit_atoi - Converts a string to an integer for use as exit code.
 * @s: String to be converted
 *
 * Return: Integer, or -1 if string it failed requirements.
 */
int exit_atoi(char *s)
{
	int i = 0, d = 0, n = 0, digit = 0;

	while (s[i])
	{
		if (i > 9 || (s[i] < '0' || s[i] > '9'))
			return (-1);
		digit = s[i++] - '0';
		if (d % 2)
			digit = -digit;
		n = n * 10 + digit;
	}

	return (n);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i = 0, d = 0, n = 0, f = 0, digit = 0;

	while (s[i] && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

