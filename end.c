#include "main.h"

/**
 * eof - Ends the program in case of eof.
 * @buffer: malloc'ed buffer for commandline.
 * @env_head: Head pointer to linked list of environment variables.
 * @flag: To know whether to print new line or not.
 */
void eof(char *buffer, env_node *env_head, char flag)
{
	(void)flag;
	free_env_list(env_head);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * error_exit - Exits in case of an error.
 * @msg: Error message.
 * @env_head: Head pointer to linked list of environment variables.
 */
void error_exit(char *msg, env_node *env_head)
{
	write_to_stderr(msg, NULL, 0, NULL, NULL);
	free_env_list(env_head);
	exit(EXIT_FAILURE);
}

/**
 * exit_sh - Handles the exit built-in.
 * @arr_tokens: Array of tokens.
 * @buffer: Commandline buffer.
 * @env_head: Head pointer to linked list of environment variables.
 */
void exit_sh(char **arr_tokens, char *buffer, env_node *env_head)
{
	free_env_list(env_head);
	free(buffer);
	free(arr_tokens);
	exit(EXIT_SUCCESS);
}

/**
 * exit_fail - Exits the program after program has processed tokens.
 * @msg: Error message.
 * @buffer: Commandline buffer from _getline.
 * @arr_tokens: Array of tokens.
 * @env_head: Head pointer to linked list of environment variables.
 */
void exit_fail(char *msg, char *buffer, char **arr_tokens, env_node *env_head)
{
	write_to_stderr(msg, NULL, 0, arr_tokens[0], arr_tokens[1]);
	free_env_list(env_head);
	free(buffer);
	free(arr_tokens);
	exit(EXIT_FAILURE);
}

