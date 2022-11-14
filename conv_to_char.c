#include "main.h"

/**
 * conv_to_char - Converts numbers less than 7 digits to characters.
 * @num: Integer value to convert.
 *
 * Return: Buffer containing the characters.
 */
char *conv_to_char(size_t num)
{
	int i, valid, buff_ind = 0;
	char tmp_buff[7];
	char *buff = malloc(sizeof(char) * 8);

	if (!buff)
		return (NULL);

	if (num == 0)
	{
		buff[0] = '0';
		buff[1] = '\0';
		return (buff);
	}

	for (i = 0; i < 7; i++)
		tmp_buff[i] = '0';

	while (num)
	{
		tmp_buff[--i] = (num % 10) + 48;
		num /= 10;
	}

	valid = NO;
	i = 0;
	while (i < 7)
	{
		if (tmp_buff[i] > '0')
			valid = YES;
		if (valid)
			buff[buff_ind++] = tmp_buff[i];
		i++;
	}
	buff[buff_ind] = '\0';

	return (buff);
}

