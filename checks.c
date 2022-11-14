#include "main.h"

/**
 * check_builtins - checks for builtin commands and runs them
 * @arr_tokens: the array to check for a builtin command
 * @env_head: Head pointer to linked list of the environment variables
 * @buffer: the temporay buffer holding input data
 *
 * Return: a call to the appropraite builtin function
 * otherwise, NULL
*/

char *check_builtins(char **arr_tokens, env_node *env_head, char *buffer)
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

/**
 * check_mul_cmds - Checks if multiple commands are present.
 * @env_head: Head pointer to the list of environment variables.
 * @av: Name of shell program.
 * @buffer: Commandline buffer from _getline.
 * @loop_count: Number of prompts printed.
 */
void check_mul_cmds(env_node *env_head, char *av, char *buffer,
		size_t *loop_count)
{
	size_t i, j = 0, buff_size = BUFF_SIZE;
	char *pass_buff, hash = NO;

	for (i = 0; buffer[i]; i++)
	{
		if (j == 0)
		{
			pass_buff = malloc(sizeof(char) * BUFF_SIZE);
			if (!pass_buff)
			{
				free(buffer), free_env_list(env_head);
				perror("malloc failed"), exit(EXIT_FAILURE);
			}
		}
		pass_buff[j++] = buffer[i];
		if (j == buff_size)
		{
			pass_buff = _realloc(pass_buff, buff_size, buff_size + BUFF_SIZE);
			if (!pass_buff)
			{
				free(buffer), free_env_list(env_head);
				perror("malloc failed"), exit(EXIT_FAILURE);
			}
			buff_size += BUFF_SIZE;
		}
		if (pass_buff[j - 1] == ';' || pass_buff[j - 1] == '#' || buffer[i + 1] == 0)
		{
			if (pass_buff[j - 1] == '#')
				hash = YES;
			if (pass_buff[j - 1] == ';' || pass_buff [j - 1] == '#')
				pass_buff[j - 1] = '\0';
			else
				pass_buff[j] = '\0';
			handle_cmds(env_head, av, pass_buff, loop_count);
			if (hash)
				break;
			j = 0;
			continue;
		}
	}
}

