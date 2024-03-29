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
 * _special_atoi - converts a string of 9 digits or less to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string,
 * otherwise 0
 */
int _special_atoi(char *s)
{
	int i, d, n, len, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	digit = 0;

	while (s[len] != '\0')
	{
		if (s[len] < '0' || s[len] > '9')
			return (0);
		len++;
	}
	if (len > 9)
		return (0);
	while (i < len)
	{
		digit = s[i] - '0';
		if (d % 2)
			digit = -digit;
		n = n * 10 + digit;
		i++;
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
