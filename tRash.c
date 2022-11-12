#include "main.h"

/**
 * main - Entry point of program.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer, **env = environ;
	size_t buff_size, loop_count = 0;
	env_node *env_head = env_list(env);

	if (!env_head)
	{
		write_to_stderr("%p: failed to run shell\n", argv[0], 0, NULL, NULL);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
		loop_count++;
		write(1, "tRash-->$ ", 10);

		if (_getline(&buffer, &buff_size, stdin) == -1)
			eof(buffer, env_head);
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}
		if (_strchr(buffer, ';'))
		{
			check_mul_cmds(env_head, argv[0], buffer, &loop_count);
			free(buffer);
			continue;
		}

		handle_cmds(env_head, argv[0], buffer, &loop_count);
	}
	return (0);
}

