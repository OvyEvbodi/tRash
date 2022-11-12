#include "main.h"

/**
 * handle_cmds - Parses command line.
 * @env_head: Head pointer to linked list of environment variables.
 * @av: Name of shell program.
 * @buffer: Commandline buffer from _getline.j
 * @loop_count: Number of prompts displayed by our program.
 *
 * Return: OK.
 */
char *handle_cmds(env_node *env_head, char *av, char *buffer,
		size_t *loop_count)
{
	char **arr_tokens, *token_zero, *cmd_full_path;

	token_zero = get_tokens(buffer, &arr_tokens, env_head);
	if (check_builtins(arr_tokens, env_head, buffer))
		return ("OK");

	cmd_full_path = _getcmd(token_zero, arr_tokens, env_head);
	if (!cmd_full_path)
	{
		if (_strcmp(token_zero, "cd") == 0)
			write_to_stderr("%p: %n: cd: can't cd to %r\n", av,
					*loop_count, NULL, arr_tokens[1]);
		else if (_strcmp(token_zero, "exit") == 0)
			write_to_stderr("%p: %n: exit: Illegal number: %r\n", av,
					*loop_count, NULL, arr_tokens[1]);
		else
			write_to_stderr("%p: %n: %c: not found\n", av,
					*loop_count, token_zero, NULL);
		free(buffer);
		free(arr_tokens);
		return ("OK");
	}

	exec_cmd(buffer, arr_tokens, cmd_full_path, env_head);
	return ("OK");
}

