#include "main.h"

/**
 * eof - Ends the program in case of eof.
 * @buffer: malloc'ed buffer for commandline.
 */
void eof(char *buffer)
{
	free(buffer);
	write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * error_exit - Exits in case of an error.
 * @msg: Error message.
 */
void error_exit(char *msg)
{
	write_to_stderr(msg, NULL, 0, NULL, NULL);
	exit(EXIT_FAILURE);
}

/**
 * exit_sh - Handles the exit built-in.
 * @arr_tokens: Array of tokens.
 * @buffer: Commandline buffer.
 */
void exit_sh(char **arr_tokens, char *buffer)
{
	free(buffer);
	free(arr_tokens);
	exit(EXIT_SUCCESS);
}

/**
 * exit_fail - Exits the program after program has processed tokens.
 * @msg: Error message.
 * @buffer: Commandline buffer from _getline.
 * @arr_token: Array of tokens.
 */
void exit_fail(char *msg, char *buffer, char **arr_tokens)
{
	write_to_stderr(msg, NULL, 0, arr_tokens[0], arr_tokens[1]);
	free(buffer);
	free(arr_tokens);
	exit(EXIT_FAILURE);
}

