#include "main.h"

/**
 * handle_env_name - Prepares the name of the variable to be added to the list.
 * @name: Address of name.
 * @buff: Temporary buffer.
 * @buff_ind: Index in buffer.
 * @flag: Utility flag.
 * @k: Counter.
 *
 * Return: Returns NULL on error, ok if successful.
 */
char *handle_env_name(char **name, char *buff, size_t buff_ind, size_t *flag,
		size_t *k)
{
	(*flag)++;
	if (*flag > 1)
		return (NULL);
	name[0] = malloc(sizeof(char) * buff_ind + 1);
	if (!name[0])
	{
		free(buff);
		return (NULL);
	}
	for (*k = 0; *k < buff_ind; (*k)++)
		name[0][*k] = buff[*k];
	name[0][*k] = '\0';
	return ("ok");
}

/**
 * handle_env_value - Allocates memory for storing the value of the variable.
 * @env: List of environment variables.
 * @value: Value of the variable.
 * @buff: Temporary buffer.
 * @name: Name of variable.
 * @flag: Utility flag.
 * @i: Index of variable.
 * @j: Index of character in variable.
 * @size: Size of memory to allocate.
 *
 * Return: ok if successful, NULL if failed.
 */
char *handle_env_value(char **env, char **value, char *buff, char *name,
		size_t *flag, size_t i, size_t *j, size_t *size)
{
	size_t tmp = *j;

	(*flag)++;
	while (env[i][*j])
		(*size)++, (*j)++;
	*j = tmp;
	value[0] = malloc(sizeof(char) * *size + 1);
	if (!value)
	{
		free(buff);
		free(name);
		return (NULL);
	}
	return ("ok");
}

/**
 * env_list - Starts the process of creating a linked list of env variables.
 * @env: An array of environment variables.
 *
 * Return: Returns the head pointer to the list.
 */
env_node *env_list(char **env)
{
	size_t i, j, k, buff_ind, flag, size, node_start = NO;
	char *name = NULL, *value = NULL, *buff = malloc(BUFF_SIZE);
	env_node *head = NULL;

	for (i = 0; env[i]; i++)
	{
		flag = 0, size = 0, buff_ind = 0;
		for (j = 0; env[i][j]; j++)
		{
			if (env[i][j] == '=')
			{
				handle_env_name(&name, buff, buff_ind, &flag, &k);
				continue;
			}
			if (flag == 1)
				handle_env_value(env, &value, buff, name, &flag, i, &j, &size);
			if (flag > 1)
			{
				for (k = 0; env[i][j]; k++)
					value[k] = env[i][j++];
				value[k] = '\0';
				break;
			}
			buff[buff_ind++] = env[i][j];
		}
		if (name && value)
		{
			if (node_start == NO)
				node_start = YES, head = create_env_list(&head, name, value);
			else
				create_env_list(&head, name, value);
		}
	}
	free(buff);
	return (head);
}

/**
 * free_env_list - Deletes the entire linked list of environement variables.
 * @head: Head pointer to the list.
 */
void free_env_list(env_node *head)
{
	if (head)
	{
		free_env_list(head->next);
		free(head->name);
		free(head->value);
		free(head);
	}
}

