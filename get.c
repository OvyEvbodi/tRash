#include "main.h"

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
		path = _strdup(cmd);
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
 * get_tokens - Tokenizes commandline and seperates it into command and args.
 * @buffer: malloc'ed buffer used to read commandline.
 * @arr_tokens: Array of tokens.
 *
 * Return: Pointer to first token, or NULL if failed.
 */
char *get_tokens(char *buffer, char ***arr_tokens)
{
	char *token_zero = NULL, *token = NULL, *delim_str = " \t\n\r\a", i = 0;
	size_t buff_size = 70;

	*arr_tokens = malloc(sizeof(char *) * buff_size);
	if (!*arr_tokens)
	{
		free(buffer);
		error_exit("error: could not tokenize\n");
	}

	token = _strtok(buffer, delim_str);
	arr_tokens[0][i++] = token;
	token_zero = token;

	while (token)
	{
		if (i == buff_size)
		{
			*arr_tokens = _realloc(*arr_tokens, sizeof(char *) * buff_size,
					sizeof(char *) * (buff_size + 70));
			if (!*arr_tokens)
			{
				free(buffer);
				error_exit("error: could not tokenize\n");
			}
			buff_size += 70;
		}
		token = _strtok(NULL, delim_str);
		arr_tokens[0][i++] = token;
	}
	arr_tokens[0][i] = NULL;

	return (token_zero);
}

