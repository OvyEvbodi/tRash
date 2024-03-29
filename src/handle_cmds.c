#include "../include/tRash.h"

/**
 * display_err - Displays an error message and sets status in case of anomaly.
 * @token_zero: Command entered.
 * @arr_tokens: Array of tokens.
 * @loop_count: Count of the current command line.
 * @av: Name of program.
 * @status: Pointer to the exit status of last command.
 */
void display_err(char *token_zero, char **arr_tokens, size_t loop_count,
		char *av, int *status)
{
	if (_strcmp(token_zero, "cd") == 0)
	{
		if (arr_tokens[1])
			write_to_stderr("%p: %n: cd: can't cd to %r\n", av,
				loop_count, NULL, arr_tokens[1]);
		*status = 2;
	}
	else if (_strcmp(token_zero, "exit") == 0)
	{
		write_to_stderr("%p: %n: exit: Illegal number: %r\n", av,
				loop_count, NULL, arr_tokens[1]), *status = 2;
	}
	else
	{
		write_to_stderr("%p: %n: %c: not found\n", av,
				loop_count, token_zero, NULL), *status = 127;
	}
}

/**
 * handle_cmds - Parses command line.
 * @env_head: Head pointer to linked list of environment variables.
 * @av: Name of shell program.
 * @buffer: Commandline buffer from _getline.
 * @loop_count: Number of prompts displayed by our program.
 * @status: Exit status.
 */
void handle_cmds(env_node *env_head, char *av, char *buffer,
		size_t *loop_count, int *status)
{
	char **arr_tokens = NULL, *token_zero = NULL, *cmd_full_path = NULL;

	if (!*buffer)
	{
		free(buffer);
		return;
	}

	token_zero = get_tokens(buffer, &arr_tokens, env_head);
	if (!token_zero || !*token_zero)
	{
		free(buffer), free(arr_tokens);
		return;
	}

	if (check_builtins(arr_tokens, env_head, buffer, *status))
		return;

	cmd_full_path = _getcmd(token_zero, env_head);
	if (!cmd_full_path)
	{
		display_err(token_zero, arr_tokens, *loop_count, av, status);
		free(buffer), free(arr_tokens);
		return;
	}

	*status = exec_cmd(buffer, arr_tokens, cmd_full_path, av, *loop_count,
			env_head, *status);
}
