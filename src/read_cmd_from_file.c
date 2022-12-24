#include "../include/tRash.h"

/**
 * read_cmd_from_file - Attempts to read a file containing commands.
 * @env_head: Head pointer to linked list of environment variables.
 * @av: The program name.
 * @av1: Name of file containing commands.
 */
void read_cmd_from_file(env_node *env_head, char *av, char *av1)
{
	ssize_t rd_fd;
	size_t buff_size, loop_count = 0;
	char *buffer = NULL, *semi_colon;
	static int status;

	rd_fd = open(av1, O_RDONLY);
	if (rd_fd == -1)
	{
		write_to_stderr("%p: %n: Can't open %c\n", av, loop_count, av1, NULL);
		free_env_list(env_head);
		exit(127);
	}

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
		loop_count++;
		if (_getline(&buffer, &buff_size, rd_fd) == -1)
			eof(buffer, env_head, status);
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}
		semi_colon = _strchr(buffer, ';');
		if (semi_colon)
			*semi_colon = '\0';
		handle_cmds(env_head, av1, buffer, &loop_count, &status);
	}
}
