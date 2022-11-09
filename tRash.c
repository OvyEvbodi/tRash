#include "main.h"

/**
 * main - Entry point of program.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer, **arr_tokens, *token_zero, *cmd_full_path;
	char **env = environ;
	size_t buff_size, loop_count = 0;

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
		loop_count++;
		write(1, "tRash-->$ ", 10);

		if (_getline(&buffer, &buff_size, stdin) == -1)
			eof(buffer);
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}

		token_zero = get_tokens(buffer, &arr_tokens);
		if (builtins(arr_tokens, env, buffer))
			continue;

		cmd_full_path = _getcmd(token_zero, arr_tokens, env);
		if (!cmd_full_path)
		{
			if (_strcmp(token_zero, "cd") == 0)
				write_to_stderr("%p: %n: cd: can't cd to %r\n", argv[0],
						loop_count, NULL, arr_tokens[1]);
			else if (_strcmp(token_zero, "exit") == 0)
				write_to_stderr("%p: %n: exit: Illegal number: %r\n", argv[0],
						loop_count, NULL, arr_tokens[1]);
			else
				write_to_stderr("%p: %n: %c: not found\n", argv[0],
						loop_count, token_zero, NULL);
			free(buffer);
			free(arr_tokens);
			continue;
		}

		exec_cmd(buffer, arr_tokens, cmd_full_path, env);
	}
	return (0);
}

