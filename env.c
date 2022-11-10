#include "main.h"

/**
 * create_env_node - Creates a new node to store an environment variable.
 * @name: Name of variable.
 * @value: Value of variable.
 *
 * Return: Pointer to new node.
 */
env_node *create_env_node(char *name, char *value)
{
	env_node *new = malloc(sizeof(env_node));

	if (!new)
		return (NULL);

	new->name = _strdup(name);
	if (!new->name)
		return (NULL);

	new->equals = "=";
	new->value = _strdup(value);
	if (!new->value)
		return (NULL);
	new->next = NULL;
	return (new);
}

/**
 * add_to_existing - Adds a new variable to an existing list of variables.
 * @head: Address of the head pointer of list.
 * @name: Name of variable to add.
 * @value: Value of the variable.
 *
 * Return: Pointer to new variable.
 */
env_node *add_to_existing(env_node **head, char *name, char *value)
{
	env_node *tmp;

	if (*head)
		tmp = add_to_existing(&(*head)->next, name, value);
	else
		*head = create_env_node(name, value), tmp = *head;
	return (tmp);
}

/**
 * create_env_list - Makes the environ into a linked list.
 * @head: Address of the head pointer.
 * @name: Name of variable.
 * @value: Value of variable.
 *
 * Return: Returns a pointer to the head node.
 */
env_node *create_env_list(env_node **head, char *name, char *value)
{
	env_node *tmp;

	if (*head)
	{
		tmp = create_env_list(&(*head)->next, name, value);
	}
	else
	{
		*head = create_env_node(name, value);
		tmp = *head;
		free(name);
		free(value);
	}
	return (tmp);
}

/**
 * replace_env_node - Changes the value of an environment variable.
 * @head: Head pointer.
 * @name: Name of variable.
 * @value: New value of variable.
 *
 * Return: Pointer to replaced node.
 */
env_node *replace_env_node(env_node *head, char *name, char *value)
{
	env_node *tmp;

	for (tmp = head; tmp; tmp = tmp->next)
	{
		if (_strcmp(tmp->name, name) == 0)
		{
			free(tmp->value);
			tmp->value = _strdup(value);
			if (!tmp->value)
				return (NULL);
			return (head);
		}
	}
	return (add_to_existing(&head, name, value));
}

/**
 * delete_env_node - Deletes a variable in the list.
 * @head: Head pointer.
 * @name: Name of variable to delete.
 */
void delete_env_node(env_node *head, char *name)
{
	env_node *tmp = head, *tmp2;

	if (_strcmp(tmp->name, name) == 0)
	{
		free(tmp->name);
		free(tmp->value);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
		return;
	}

	while (tmp)
	{
		if (_strcmp(tmp->next->name, name) == 0)
		{
			if (tmp->next->next == NULL)
			{
				free(tmp->next->name);
				free(tmp->next->value);
				free(tmp->next);
				tmp->next = NULL;
				break;
			}
			else
			{
				tmp2 = tmp->next->next;
				free(tmp->next->name);
				free(tmp->next->value);
				free(tmp->next);
				tmp->next = tmp2;
				break;
			}
		}
		tmp = tmp->next;
	}
}

char *handle_env_name(char **name, char *buff, size_t buff_ind, size_t *flag, size_t *k)
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
 * env_list - Starts the process of creating a linked list of env variables.
 * @env: An array of environment variables.
 *
 * Return: Returns the head pointer to the list.
 */
env_node *env_list(char **env)
{
	size_t i, j, k, tmp, buff_ind, flag, size, node_start = NO;
	char *buff, *name = NULL, *value = NULL;
	env_node *head = NULL;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (!buff)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		flag = 0, size = 0, buff_ind = 0;
		for (j = 0; env[i][j]; j++)
		{
			if (env[i][j] == '=')
			{
				flag++;
				if (flag > 1)
					return (NULL);
				name = malloc(sizeof(char) * buff_ind + 1);
				if (!name)
				{
					free(buff);
					return (NULL);
				}
				for (k = 0; k < buff_ind; k++)
					name[k] = buff[k];
				name[k] = '\0';
				continue;
			}
			if (flag == 1)
			{
				flag++, tmp = j;
				while (env[i][j])
					size++, j++;
				j = tmp;
				value = malloc(sizeof(char) * size + 1);
				if (!value)
				{
					free(buff);
					free(name);
					return (NULL);
				}
			}
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

