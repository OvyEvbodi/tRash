#include "main.h"

/**
 * exec_cmd - Handles execution of a command.
 * @buffer: Commandline buffer used by _getline.
 * @arr_tokens: Array of tokens.
 * @cmd_full_path - Full path to command.
 * @env: List of environment variables.
 */
void exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path, char **env)
{
	char *echo_arg_string = NULL;
	pid_t pid = fork();
	arr_tokens[0] = cmd_full_path;

	if (_strstr(cmd_full_path, "echo"))
		echo_arg_string = sort_echo(&arr_tokens, env);

	if (pid == 0)
	{
		if (execve(cmd_full_path, arr_tokens, env) == -1)
		{
			write(2, "Error: exec failed\n", 19);
			free(cmd_full_path);
			if (echo_arg_string)
				free(echo_arg_string);
			free(arr_tokens);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (echo_arg_string)
			free(echo_arg_string);
		free(cmd_full_path);
		free(arr_tokens);
		free(buffer);
	}
}

