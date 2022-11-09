#include "main.h"

/**
 * write_to_stderr - Prints a formatted string to standard error stream.
 * @format: Formatted string.
 * @tok_zero: Command inputed by user.
 * @tok_one: First argument to command.
 *
 * Return: Number of characters printed, or -1 if failed.
 */
int write_to_stderr(char *format, char *arg_zero, size_t loop_count,
		char *tok_zero, char *tok_one)
{
	int i, j = 0, buff_ind = 0;
	char buffer[BUFF_SIZE], *num;

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				/* p for program name. */
				/* n for number (loop_count). */
				/* c for command. Anything for first argument to command. */
				case 'p':
					for (j = 0; arg_zero && arg_zero[j]; j++)
						buffer[buff_ind++] = arg_zero[j];
					break;
				case 'n':
					num = conv_to_char(loop_count);
					if (num)
					{
						for (j = 0; num[j]; j++)
							buffer[buff_ind++] = num[j];
						free(num);
						break;
					}
					return (-1);
				case 'c':
					for (j = 0; tok_zero && tok_zero[j]; j++)
						buffer[buff_ind++] = tok_zero[j];
					break;
				default:
					for (j = 0; tok_one && tok_one[j]; j++)
						buffer[buff_ind++] = tok_one[j];
			}
			i++;
			continue;
		}
		buffer[buff_ind++] = format[i];
	}
	return (write(2, buffer, buff_ind));
}

