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
		status = _special_atoi(arr_tokens[1]);
	status %= 256;
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
	char *old_buff, *buff;
	char *new, *old;
	int i = 0;

	if (arr_tokens[2])
		return (NULL);

	old_buff = NULL;
	old_buff = getcwd(old_buff, 0);

	if (arr_tokens[1])
		var_val = arr_tokens[1];
	else
		var_val = _getenv("HOME", env);

	if (chdir(var_val) == 0)
	{
		buff = NULL;
		buff = getcwd(buff, 0);
		new = _strdup(buff);
		old = _strdup(old_buff);

		setenviron("OLDPWD",old, 1);
		setenviron("PWD",new, 1);
		free(buff);
		free(old_buff);
		free(new);
		free(old);
		free(buffer);
 		free(arr_tokens);
		return("ok");
	}
	free(old_buff);

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

	if (!arr_tokens[1] || !arr_tokens[2] || !arr_tokens[3])
		return (NULL);
	overwrite = _atoi(arr_tokens[3]);
	if (setenviron(arr_tokens[1], arr_tokens[2], overwrite))
		return (NULL);
	else
	{
		free(buffer);
		free(arr_tokens);
	}
	return ("ok");
}

/**
 * setenviron - sets an environment variable
 * @name: the variable identifier to be added/updated
 * @value: the value of the variable
 * @overwrite: the flag to overwrite an existing variable,
 * 0 for no, other numbers for yes
 *
 * Return: 0 on success,
 * otherwise, -1
*/

int setenviron(char *name, char *value, int overwrite)
{
	extern char **environ;
	char **env = environ;
	char *var_exists, *buff, *temp;
	int i = 0;

	if (!name || !value)
		return (-1);

	buff = malloc(sizeof(_strlen(name)) + sizeof(_strlen(value)) + 2);
	if (!buff)
		return (-1);

	temp = str_concat(name, "=");
	temp = str_concat(temp, value);
	buff = temp;

	for (; env[i]; i++)
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0)
		{
			if (overwrite)
			{
				env[i] = buff;
				break;
			}
			else
				break;
		}
	}
	/*if variable does not exist, add it to the environment*/
	
	buff = NULL;
	free(buff);
	return(0);
}
