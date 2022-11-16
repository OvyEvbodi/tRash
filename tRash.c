#include "main.h"

/**
 * main - Entry point of program.
 * @argc: Number of arguments.
 * @argv: Array of strings.
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
		write_to_stderr("%p: %n: failed to run shell\n", argv[0],
				loop_count, NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if (argc > 1)
		read_cmd_from_file(env_head, argv[0], argv[1]);

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
		loop_count++;
		write(0, "tRash>>$ ", 9);

		if (_getline(&buffer, &buff_size, 0) == -1)
			eof(buffer, env_head, 1);
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
	exit(EXIT_SUCCESS);
}

