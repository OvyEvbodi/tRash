#include "main.h"

/**
 * read_cmd_from_file - Attempts to read a file containing commands.
 * @env_head: Head pointer to linked list of environment variables.
 * @av: The program name.
 * @av1: Name of file containing commands.
 */
void read_cmd_from_file(env_node *env_head, char *av, char *av1)
{
	ssize_t rd_fd, buff_size, loop_count = 0;
	char *buffer = NULL, *semi_colon;

	rd_fd = open(av1, O_RDONLY);
	if (rd_fd == -1)
	{
		if (errno == EACCES)
			write_to_stderr("%p: %n: cannot open %c: Permission denied\n",
					av, loop_count, av1, NULL);
		else if (errno == ENOENT)
			write_to_stderr("%p: %n: cannot open %c: No such file\n",
					av, loop_count, av1, NULL);
		free_env_list(env_head);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
		loop_count++;
		if (_getline(&buffer, &buff_size, rd_fd) == -1)
			eof(buffer, env_head, 2);
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue;
		}
		semi_colon = _strchr(buffer, ';');
		if (semi_colon)
			*semi_colon = '\0';
		handle_cmds(env_head, av, buffer, &loop_count);
	}
}

