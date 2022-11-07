#include "main.h"

extern char **environ;

/**
 * _getenv - Gets the value of an evironment variable if it exists.
 * @var: Environment variable to search for.
 * @env: List of environment variables.
 *
 * Return: The value of the environment variable, or NULL if not present.
*/
char *_getenv(char *var, char **env)
{
	char *var_val = NULL;
	size_t var_len = _strlen(var);

	while (*env)
	{
		if (_strncmp(*env, var, var_len) == 0)
		{
			var_val = *env + var_len + 1;
			break;
		}
		env++;
	}

	return (var_val);
}

/**
 * full_cmd - Gets the full path to the executable for a command.
 * @cmd: Command.
 * @path: Value of PATH variable.
 *
 * Return: The absolute path of the command, or NULL if not present.
 */
char *full_cmd(char *cmd, char *path)
{
	struct stat sfile;
	char **path_arr;
	size_t i = 0;
	char *tmp_full_path, *full_path;

	path_arr = _strtow(path);
	if (!path_arr)
		return (NULL);

	while (path_arr[i])
	{
		tmp_full_path = str_concat(path_arr[i++], "/");
		full_path = str_concat(tmp_full_path, cmd);
		free(tmp_full_path);
		tmp_full_path = NULL;
		if (stat(full_path, &sfile) == 0)
			break;

		free(full_path);
		full_path = NULL;
	}
	for (i = 0; path_arr[i]; i++)
		free(path_arr[i]);
	free(path_arr);

	return (full_path);
}

/**
 * _get_cmd - Takes care of the format for running a command.
 * @cmd: Command.
 * @env: List of environment variables.
 *
 * Return: Format in which command can be run, or NULL if it fails.
 */
char *_getcmd(char *cmd, char **arr_tokens, char **env)
{
	char *path, *var_val;

	if (_strchr(cmd, '/'))
	{
		path = cmd;
	}
	else
	{
		var_val = _getenv("PATH", env);
		if (var_val == NULL)
			return (NULL);
		path = full_cmd(cmd, var_val);
	}

	return (path);
}

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
	write(2, msg, _strlen(msg));
	exit(EXIT_FAILURE);
}

/**
 * get_tokens - Tokenizes commandline and seperates it into command and args.
 * @buffer: malloc'ed buffer used to read commandline.
 * @arr_tokens: Array of tokens.
 *
 * Return: Pointer to first token, or NULL if failed.
 */
char *get_tokens(char *buffer, char ***arr_tokens)
{
	char *token_zero = NULL, *token = NULL, *delim_str = " \t\n\r\a", i = 0;

	*arr_tokens = malloc(sizeof(char *) * 64);
	if (!*arr_tokens)
	{
		free(buffer);
		error_exit("could not tokenize\n");
	}

	token = _strtok(buffer, delim_str);
//	token = _strdup(token);
	arr_tokens[0][i++] = token;
	token_zero = token;

	while (token)
	{
		token = _strtok(NULL, delim_str);
//		token = _strdup(token);
		arr_tokens[0][i++] = token;
	}
	arr_tokens[0][i] = NULL;

	return (token_zero);
}

/**
 * change_dir - Handles the cd built-in.
 * @arr_tokens: Array of tokens.
 * @env: List of environment variables.
 *
 * Return: 0 on success, -1 if it fails.
 */
// int change_dir(char **arr_tokens, char **env)
// {
// 	char *var_val;

// 	if (arr_tokens[2])
// 		return (-1);
// 	if (arr_tokens[1])
// 	{
// 		if (chdir(arr_tokens[1]))
// 			return(-1);
// 	}
// 	else
// 	{
// 		var_val = _getenv("HOME", env);
// 		if (chdir(var_val))
// 			return (-1);
// 	}
// 	return (0);
// }

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
	write(2, msg, _strlen(msg));
	free(buffer);
	free(arr_tokens);
	exit(EXIT_FAILURE);
}

/**
 * check_builtins - Checks whether command is a built-in and calls its function.
 * @arr_tokens: Array of tokens.
 * @buffer: Used to store commandline by _getline.
 * @env: List of environment variables.
 *
 * Return: 0 if command is a built-in, 1 otherwise.
 */
// int check_builtins(char **arr_tokens, char *buffer, char **env)
// {
// 	//loop through array of structs with each builtin function
// 	if (_strcmp(arr_tokens[0], "cd") == 0)
// 	{
// 		if (change_dir(arr_tokens, env) == 0)
// 		{
// 			free(buffer);
// 			free(arr_tokens);
// 			return (0);
// 		}
// 		else
// 			exit_fail("wrong number of arguments to cd\n",
// 					buffer, arr_tokens);
// 	}

// 	if (_strcmp(arr_tokens[0], "exit") == 0)
// 		exit_sh(arr_tokens, buffer);

// 	return (1);
// }

/**
 * exec_cmd - Handles execution of a commands.
 * @buffer: Commandline buffer used by _getline.
 * @arr_tokens: Array of tokens.
 * @cmd_full_path - Full path to command.
 * @env: List of environment variables.
 */
void exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path, char **env)
{
	pid_t pid = fork();
	int status;
	arr_tokens[0] = cmd_full_path;

	if (pid == 0)
	{
		if (execve(cmd_full_path, arr_tokens, env) == -1)
		{
			write(2, "Error: exec failed\n", 19);
			free(cmd_full_path);
			free(arr_tokens);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd_full_path);
		free(arr_tokens);
		free(buffer);
	}
}

/**
 * main - Entry point of program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *buffer, **arr_tokens, *token_zero, *cmd_full_path;
	char **env = environ;
	size_t buff_size;

	while (1)
	{
		buffer = NULL;
		buff_size = 0;
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
			write(2, "not found\n", 10);
			free(buffer);
			free(arr_tokens);
			continue;
		}

		exec_cmd(buffer, arr_tokens, cmd_full_path, env);
	}
	return (0);
}

