#include "main.h"

/**
 * exit - exits a process
 * @arr_tokens: the array to check for a builtin command
 * @env: a pointer to the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: void on success,
 * otherwise, NULL
*/

char *_exit_th(char **arr_tokens, char **env, char *buffer)
{
	int status;

	if (!arr_tokens[1])
		status = 0;
	else
		status = _atoi(arr_tokens[1]);
	free(arr_tokens);
	free(buffer);
	exit(status);

	return (NULL);
}

/**
 * cd - changes the present working directory
 * @arr_tokens: the array to check for a builtin command
 * @env: a pointer to the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: ok, if successfull,
 * otherwise, NULL
*/

char *cd(char **arr_tokens, char **env, char *buffer)
{
	char *var_val;

	if (arr_tokens[2])
		return (NULL);
	if (arr_tokens[1])
	{
		if (chdir(arr_tokens[1]) == 0)
		{
			free(buffer);
 			free(arr_tokens);
			return("ok");
		}
	}
	else
	{
		var_val = _getenv("HOME", env);
		if (chdir(var_val) == 0)
		{
			free(buffer);
 			free(arr_tokens);
			return ("ok");
		}
	}

	return (NULL);
}

/**
 * _setenv - sets an environment variable
 * @arr_tokens: the array to check for a builtin command
 * @env: a pointer to the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: ok on success,
 * otherwise, NULL
*/

char *_setenv(char **arr_tokens, char **env, char *buffer)
{
	int overwrite;

	overwrite = _atoi(arr_tokens[3]);
	if (setenv(arr_tokens[1], arr_tokens[2], overwrite))
		return (NULL);
	else
		printf("setenv success\n");
	return ("ok");
}

/**
 * _putenv - sets an environment variable
 * @arr_tokens: the array to check for a builtin command
 * @env: a pointer to the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: ok on success,
 * otherwise, NULL
*/

char *_putenv(char **arr_tokens, char **env, char *buffer)
{
	if (putenv(arr_tokens[1]))
		return (NULL);
	else
		printf("putenv success\n");
	return ("ok");
}

