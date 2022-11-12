#include "main.h"

/**
 * builtins - checks for builtin commands and runs them
 * @arr_tokens: the array to check for a builtin command
 * @env_head: Head pointer to linked list of the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: a call to the appropraite builtin function
 * otherwise, NULL
*/

char *builtins(char **arr_tokens, env_node *env_head, char *buffer)
{
	int i = 0;

	cmds ops[] = {
		{"exit", _exit_th},
		{"cd", cd},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	while (ops[i].name)
	{
		if (_strcmp(ops[i].name, arr_tokens[0]) == 0)
			return (ops[i].op(arr_tokens, env_head, buffer));
		i++;
	}

	return (NULL);
}

