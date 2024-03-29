#include "../include/tRash.h"

/**
 * arrange_environ - Makes linked list of variables into an array of strings.
 * @_environ: Array of strings.
 * @head: Head pointer to the linked list of environment variables.
 *
 * Return: The initialized array of strings, or NULL if failed.
 */
char **arrange_environ(char **_environ, env_node *head)
{
	int i = 0, size = 70;
	char *tmp;

	_environ = malloc(sizeof(char *) * size);
	if (!_environ)
		return (NULL);

	while (head)
	{
		if (i == size)
		{
			_environ = _realloc(_environ, sizeof(char *) * size,
					sizeof(char *) * (size + (size / 2)));
			if (!_environ)
				return (NULL);
			size += (size / 2);
		}
		tmp = str_concat(head->name, head->equals);
		_environ[i++] = str_concat(tmp, head->value);
		free(tmp);
		head = head->next;
	}
	if (i == size)
	{
		_environ = _realloc(_environ, sizeof(char *) * size,
				sizeof(char *) * (size + 1));
		if (!_environ)
			return (NULL);
		size++;
	}
	_environ[i] = NULL;
	return (_environ);
}

/**
 * free_environ - Frees the array of strings of environment variables.
 * @env: Array of environment variables.
 */
void free_environ(char **env)
{
	int i = 0;

	if (env)
	{
		while (env[i])
			free(env[i++]);
		free(env);
	}
}

/**
 * free_for_execve - Frees allocated memory within the execve function.
 * @cmd: Command full path.
 * @echo_arg_string: Argument to echo.
 * @buff: Coomandline buffer from getline.
 * @arr_tokens: Pointers to tokens within buffer.
 * @_env: Array of environment variables with their values.
 */
void free_for_execve(char *cmd, char *echo_arg_string, char *buff,
		char **arr_tokens, char **_env)
{
	if (echo_arg_string)
		free(echo_arg_string);
	free(cmd);
	free(buff);
	free(arr_tokens);
	free_environ(_env);
}

/**
 * exec_cmd - Handles execution of a command.
 * @buffer: Commandline buffer used by _getline.
 * @arr_tokens: Array of tokens.
 * @cmd_full_path: Full path to command.
 * @av: Name of shell program.
 * @loop_count: Loop iteration.
 * @env_head: Head pointer to linked List of environment variables.
 * @status: Exit status.
 *
 * Return: Exit status.
 */
int exec_cmd(char *buffer, char **arr_tokens, char *cmd_full_path, char *av,
		size_t loop_count, env_node *env_head, int status)
{
	char *echo_arg_string = NULL, **_env = NULL;
	pid_t pid;

	if (_strstr(cmd_full_path, "echo"))
		echo_arg_string = sort_echo(&arr_tokens, env_head, status);

	_env = arrange_environ(_env, env_head);

	pid = fork();
	if (pid == -1)
	{
		write_to_stderr("%p: %n: %c: ", av, loop_count, arr_tokens[0], NULL);
		perror("");
		free_for_execve(cmd_full_path, echo_arg_string, buffer, arr_tokens, _env);
		free_env_list(env_head);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(cmd_full_path, arr_tokens, _env) == -1)
		{
			write_to_stderr("%p: %n: %c: ", av, loop_count, arr_tokens[0], NULL);
			perror("");
			free_for_execve(cmd_full_path, echo_arg_string, buffer, arr_tokens, _env);
			free_env_list(env_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_for_execve(cmd_full_path, echo_arg_string, buffer, arr_tokens, _env);
	}
	return (WEXITSTATUS(status));
}
